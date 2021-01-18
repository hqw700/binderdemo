package demo;

import android.os.RemoteException;
import android.util.Log;

import com.android.internal.util.IndentingPrintWriter;

import java.io.FileDescriptor;
import java.io.PrintWriter;

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

    @Override
    public void dump(FileDescriptor fd, PrintWriter writer, String[] args) {
        final IndentingPrintWriter pw = new IndentingPrintWriter(writer, "  ");
        pw.println("test_server dump:");
        pw.increaseIndent();
        pw.println("this is Java implementation");
    }
}
