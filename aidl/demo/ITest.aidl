package demo;

import demo.ICallback;
import android.os.PersistableBundle;
interface ITest
{
    void ping();
    oneway void pingOneway();
    void sendIn(in PersistableBundle data);
    void sendOut(out PersistableBundle data);
    void sendInOut(inout PersistableBundle data);
    int sum(int x, int y);
    void registerCallback(ICallback cb);
    void unregisterCallback(ICallback cb);
}