package simplestcall;

import android.os.Bundle;
import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

public class Main {
    private static final String TAG = "SimplestCall";

    public static void main(String[] args) {
        IBinder service = ServiceManager.getService("test_server");
        final Parcel data = Parcel.obtain();
        final Parcel reply = Parcel.obtain();
        data.writeInterfaceToken("demo.ITest");
        try {
            service.transact(IBinder.FIRST_CALL_TRANSACTION + 0, data, reply, 0 /* flags */);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        System.out.println(reply.toString());
        reply.recycle();
        data.recycle();
    }
}