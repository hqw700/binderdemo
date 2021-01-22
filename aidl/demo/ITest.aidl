package demo;

import demo.ICallback;
interface ITest
{
    void ping();
    int sum(int x, int y);
    void register(ICallback cb);
    void unregister(ICallback cb);
}