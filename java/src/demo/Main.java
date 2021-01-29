package demo;

import android.os.Bundle;
import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

public class Main {
    private static final String TAG_S = "JAVA_BINDER.Server";
    private static final String TAG_C = "JAVA_BINDER.Client";
    private static final String BINDER_NAME = "test_server";

    public static void main(String[] args) {
        int len = args.length;
        if (len == 0) {
            Log.d(TAG_S, "This is TestServer");
            TestServer testServer = new TestServer();
            ServiceManager.addService(BINDER_NAME, testServer);
        } else if ("inout".equals(args[0])){
            inoutTest();
        }else {
            Log.d(TAG_C, "This is TestClient");
            ITest testClient = ITest.Stub.asInterface(ServiceManager.getService(BINDER_NAME));
            if (testClient == null) {
                System.err.println("TestServer is null");
                System.exit(-1);
            }
            try {

                int v1 = Integer.parseInt(args[0]);
                int v2 = Integer.parseInt(args[1]);
                Log.d(TAG_C, String.format("sum (%d,%d)", v1, v2));
                int ret = testClient.sum(v1, v2);
                Log.d(TAG_C, String.format("sum (%d,%d) return %d", v1, v2, ret));
                System.out.println(ret);

                testClient.asBinder().linkToDeath(new IBinder.DeathRecipient() {
                    @Override
                    public void binderDied() {
                        Log.d("binder", "binderDied calling~!");
                        System.out.println("binderDied calling");
                        System.exit(0);
                    }
                }, 0);

                testClient.registerCallback(new ICallback.Stub() {
                    @Override
                    public void onCallback(String str) throws RemoteException {
                        Log.d(TAG_C, "This is onCallback");
                    }
                });

                Log.d(TAG_C, "ping, 5s callback");
                testClient.ping();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
        for (;;);
    }

    private static void inoutTest() {
        Log.d(TAG_C, "This is TestClient");
        ITest testClient = ITest.Stub.asInterface(ServiceManager.getService(BINDER_NAME));
        if (testClient == null) {
            System.err.println("TestServer is null");
            System.exit(-1);
        }

        try {
            Bundle data_in = new Bundle();
            data_in.putString("data", "client");
            testClient.sendIn(data_in);
            Log.d(TAG_C, "after sendIn: " + data_in.getString("data"));

            Bundle data_out = new Bundle();
            data_out.putString("data", "client");
            testClient.sendOut(data_out);
            Log.d(TAG_C, "after sendOut: " + data_out.getString("data"));

            Bundle data_inout = new Bundle();
            data_inout.putString("data", "client");
            testClient.sendInOut(data_inout);
            Log.d(TAG_C, "after sendInOut: " + data_inout.getString("data"));
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}