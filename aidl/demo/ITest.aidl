package demo;

import demo.ICallback;
interface ITest
{
    void ping();
    int sum(int x, int y);
    void registerCallback(ICallback cb);
    void unregisterCallback(ICallback cb);
}