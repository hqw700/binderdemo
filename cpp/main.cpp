#define LOG_TAG "cpp_binder"

#include <stdlib.h>

#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <demo/ITest.h>
#include <demo/BnTest.h>
#include <demo/BnCallback.h>
#include <demo/ICallback.h>

#define BINDER_NAME "test_server"

using namespace android;

#define INFO(...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
        ALOGD(__VA_ARGS__); \
    } while(0)

void assert_fail(const char *file, int line, const char *func, const char *expr) {
    INFO("assertion failed at file %s, line %d, function %s:",
         file, line, func);
    INFO("%s", expr);
    abort();
}

#define ASSERT(e) \
    do { \
        if (!(e)) \
            assert_fail(__FILE__, __LINE__, __func__, #e); \
    } while(0)

// ################# For binder server start #####################
class Test : public demo::BnTest {
    std::vector<sp<demo::ICallback>> mCallbackList;
public:
    binder::Status ping() override {
        INFO("server: ping receive ok");
        sleep(5);
        INFO("server: onCallback");
        for (auto& i : mCallbackList) {
            i->onCallback(String16("test"));
        }
        return binder::Status();
    }

    binder::Status pingOneway() override {

        return binder::Status();
    }

    binder::Status sendIn(const os::PersistableBundle &data) override {
        String16 rec;
        data.getString(String16("data"), &rec);
        INFO("server: sendIn: receive: %s", String8(rec).string());
//        rec.append(String16("server"));
//        data->putString(String16("data"), rec);
        return binder::Status();
    }

    binder::Status sendOut(os::PersistableBundle *data) override {
        String16 rec;
        data->getString(String16("data"), &rec);
        INFO("server: sendIn: receive: %s", String8(rec).string());
        rec.append(String16("server"));
        data->putString(String16("data"), rec);
        return binder::Status();
    }

    binder::Status sendInOut(os::PersistableBundle *data) override {
        String16 rec;
        data->getString(String16("data"), &rec);
        INFO("server: sendIn: receive: %s", String8(rec).string());
        rec.append(String16("server"));
        data->putString(String16("data"), rec);
        return binder::Status();
    }

    binder::Status registerCallback(const sp<::demo::ICallback> &cb) override {
        for (auto& it : mCallbackList) {
            if (IInterface::asBinder(it) == IInterface::asBinder(cb)) {
                INFO("%s: Tried to add callback %p which was already subscribed",
                     __FUNCTION__, cb.get());
                return binder::Status();
            }
        }

        mCallbackList.push_back(cb);
        return binder::Status();
    }

    binder::Status unregisterCallback(const sp<::demo::ICallback> &cb) override {
        for (auto it = mCallbackList.begin(); it != mCallbackList.end(); it++) {
            if (IInterface::asBinder(*it) == IInterface::asBinder(cb)) {
                mCallbackList.erase(it);
                INFO("server: unregisterCallback ok");
                return binder::Status().ok();
            }
        }
        return binder::Status();
    }

    binder::Status sum(int32_t v1, int32_t v2, int32_t *_aidl_return) override {
        INFO("server: sum: %d + %d", v1, v2);
        *_aidl_return = v1 + v2;
        return binder::Status();
    }

    status_t dump(int fd, const Vector<String16> &args) override {
        String8 result;
        result.append("test_server dump:\n");
        result.append("this is cpp implementation\n");
        write(fd, result.string(), result.size());
        return NO_ERROR;
    }
};
// ################# For binder server end #####################
class CallbackTest : public demo::BnCallback {
public:
    binder::Status onCallback(const String16 &str) override {
        INFO("client: onCallback, receive str: %s", String8(str).string());
        return binder::Status();
    }
};

class TestDeathRecipient : public IBinder::DeathRecipient
{
private:
    virtual void binderDied(const wp<IBinder>& who) {
        INFO("client: binderDied");
        exit(EXIT_FAILURE);
    };
};

int main(int argc, char **argv) {
    if (argc == 1) { // server
        defaultServiceManager()->addService(String16(BINDER_NAME), new Test());
        ProcessState::self()->startThreadPool();
        INFO("server: This is TestServer");
        IPCThreadState::self()->joinThreadPool();
    } else { // client
        sp<ProcessState> proc(ProcessState::self());
        ProcessState::self()->startThreadPool();
        INFO("client: We're the client, inout test");
        sp<IServiceManager> sm = defaultServiceManager();
        ASSERT(sm != 0);
        sp<IBinder> binder = sm->getService(String16(BINDER_NAME));
        ASSERT(binder != 0);
        sp<demo::ITest> test = interface_cast<demo::ITest>(binder);
        ASSERT(test != 0);

        if (strcmp(argv[1], "inout") == 0) {
            os::PersistableBundle data_in;
            data_in.putString(String16("data"),String16( "client"));
            test->sendIn(data_in);
            String16 ret_in;
            data_in.getString(String16("data"), &ret_in);
            INFO("client: after sendIn: %s", String8(ret_in).string());

            os::PersistableBundle data_out;
            data_out.putString(String16("data"),String16( "client"));
            test->sendOut(&data_out);
            String16 ret_out;
            data_out.getString(String16("data"), &ret_out);
            INFO("client: after sendOut: %s", String8(ret_out).string());

            os::PersistableBundle data_inout;
            data_inout.putString(String16("data"),String16( "client"));
            test->sendInOut(&data_inout);
            String16 ret_inout;
            data_inout.getString(String16("data"), &ret_inout);
            INFO("client: after sendInOut: %s", String8(ret_inout).string());
        } else if (strcmp(argv[1], "oneway") == 0) {
            INFO("client: ping start, sleep 5s");
            test->ping();
            INFO("client: ping end");
            INFO("client: ping one-way start, sleep 5s");
            test->pingOneway();
            INFO("client: ping one-way end");
        } else if (argc == 3) {
            int ret = 0;
            test->sum(atoi(argv[1]), atoi(argv[2]), &ret);
            INFO("client: We're the client: test->sum return: %d", ret);

            sp<CallbackTest> callback = new CallbackTest();
            test->registerCallback(callback);
            INFO("client: ping, 5s callback");
            test->ping();

            test->unregisterCallback(callback);
            INFO("client: ping again, 5s callback");
            test->ping();
        }
        IPCThreadState::self()->joinThreadPool();
    }
    return 0;
}

