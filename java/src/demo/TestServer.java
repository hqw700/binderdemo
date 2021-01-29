package demo;

import android.os.Bundle;
import android.os.RemoteException;
import android.os.RemoteCallbackList;
import android.os.DeadObjectException;
import android.util.Log;

import com.android.internal.util.IndentingPrintWriter;

import java.io.FileDescriptor;
import java.io.PrintWriter;

public class TestServer extends ITest.Stub {
    private static final String TAG = "JAVA_BINDER.Server";
    private final RemoteCallbackList<ICallback> mCallbacks = new RemoteCallbackList<ICallback>();
    @Override
    public void ping() throws RemoteException {
        Log.d(TAG, "ping receive ok, after 5s callback");
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {}

        Log.d(TAG, "ping doCallback");
        doCallback("ping");
    }

    @Override
    public void pingOneway() throws RemoteException {

    }

    @Override
    public void sendIn(Bundle data) throws RemoteException {
        String rec = data.getString("data");
        Log.d(TAG, "sendIn: receive: " + rec);
        data.putString("data", rec + "server");
    }

    @Override
    public void sendOut(Bundle data) throws RemoteException {
        String rec = data.getString("data");
        Log.d(TAG, "sendOut: receive: " + rec);
        data.putString("data", rec + "server");
    }

    @Override
    public void sendInOut(Bundle data) throws RemoteException {
        String rec = data.getString("data");
        Log.d(TAG, "sendInOut: receive: " + rec);
        data.putString("data", rec + "server");
    }

    @Override
    public int sum(int x, int y) throws RemoteException {
        Log.d(TAG, "sum " + x + " + " + y);
        return x + y;
    }

    @Override
    public void registerCallback(ICallback cb) throws RemoteException {
        Log.d(TAG, "register " + cb);
        if (cb != null) mCallbacks.register(cb);
    }

    @Override
    public void unregisterCallback(ICallback cb) throws RemoteException {
        if (cb != null) mCallbacks.unregister(cb);
    }

    protected void doCallback(String info) {
        if (mCallbacks == null || mCallbacks.getRegisteredCallbackCount() <= 0) {
            Log.d(TAG, "doCallback error");
            return;
        }
        synchronized (mCallbacks) {
            mCallbacks.beginBroadcast();
            int N = mCallbacks.getRegisteredCallbackCount();
            Log.d(TAG, "doCallback Count = " + N);
            for (int i = 0; i < N; i++) {
                try {
                    if (mCallbacks.getBroadcastItem(i) == null) {
                        continue;
                    }
                    mCallbacks.getBroadcastItem(i).onCallback(info);
                } catch (DeadObjectException e) {
                    if (mCallbacks.getBroadcastItem(i) != null)
                        mCallbacks.unregister(mCallbacks.getBroadcastItem(i));
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
            }
            mCallbacks.finishBroadcast();
        }
    }

    @Override
    public void dump(FileDescriptor fd, PrintWriter writer, String[] args) {
        final IndentingPrintWriter pw = new IndentingPrintWriter(writer, "  ");
        pw.println("test_server dump:");
        pw.increaseIndent();
        pw.println("this is Java implementation");
        int N = mCallbacks.getRegisteredCallbackCount();
        pw.println("callback register count: " + N);
        for (int i = 0; i < N; i++) {
            pw.println("callback register: " + mCallbacks.toString());
        }
    }
}
