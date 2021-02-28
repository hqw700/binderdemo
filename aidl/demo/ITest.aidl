package demo;

import demo.ICallback;
import demo.BinderData;
interface ITest
{
    void ping();
    oneway void pingOneway();
    void sendIn(in BinderData data);
    void sendOut(out BinderData data);
    void sendInOut(inout BinderData data);
    int sum(int x, int y);
    void registerCallback(ICallback cb);
    void unregisterCallback(ICallback cb);
}