package demo;

import android.os.RemoteException;
import android.util.Log;

public class TestServer extends ITest.Stub {
    private static final String TAG = "JAVA_BINDER.Server";
    @Override
    public void ping() throws RemoteException {
        Log.d(TAG, "ping receive ok");
    }

    @Override
    public int sum(int x, int y) throws RemoteException {
        Log.d(TAG, "sum " + x + " + " + y);
        return x + y;
    }
}
