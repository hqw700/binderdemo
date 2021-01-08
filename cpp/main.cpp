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
public:
    binder::Status ping() override {
        INFO("ping receive ok");
        return android::binder::Status();
    }

    binder::Status sum(int32_t v1, int32_t v2, int32_t *_aidl_return) override {
        INFO("sum: %d + %d", v1, v2);
        *_aidl_return = v1 + v2;
        return android::binder::Status();
    }
};
// ################# For binder server end #####################

int main(int argc, char **argv) {
    if (argc == 1) {
        defaultServiceManager()->addService(String16(BINDER_NAME), new Test());
        android::ProcessState::self()->startThreadPool();
        INFO("This is TestServer");
        IPCThreadState::self()->joinThreadPool();
    } else if (argc == 3) {
        INFO("We're the client:");
        sp<IServiceManager> sm = defaultServiceManager();
        ASSERT(sm != 0);
        sp<IBinder> binder = sm->getService(String16(BINDER_NAME));
        ASSERT(binder != 0);
        sp<demo::ITest> test = interface_cast<demo::ITest>(binder);
        ASSERT(test != 0);
        test->ping();
        int ret = 0;
        test->sum(atoi(argv[1]), atoi(argv[2]), &ret);
        INFO("We're the client: test->sum return: %d", ret);
    }
    return 0;
}
