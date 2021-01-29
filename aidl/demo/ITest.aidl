package demo;

import demo.ICallback;
import android.os.Bundle;
interface ITest
{
    void ping();
    oneway void pingOneway();
    void sendIn(in Bundle data);
    void sendOut(out Bundle data);
    void sendInOut(inout Bundle data);
    int sum(int x, int y);
    void registerCallback(ICallback cb);
    void unregisterCallback(ICallback cb);
}