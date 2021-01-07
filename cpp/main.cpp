

#define LOG_TAG "binder_demo"

/* For relevant code see:
    frameworks/native/{include,libs}/binder/{IInterface,Parcel}.{h,cpp}
    system/core/include/utils/{Errors,RefBase}.h
 */

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


// Where to print the parcel contents: aout, alog, aerr. alog doesn't seem to work.
#define PLOG aout


class Test : public demo::BnTest {
public:
    binder::Status ping() override {
        ALOGD("test function");
        return android::binder::Status();
    }

    binder::Status sum(int32_t v1, int32_t v2, int32_t *_aidl_return) override {
        ALOGD("get function: %d %d", v1, v2);
        *_aidl_return = 333;
        return android::binder::Status();
    }
};

int main(int argc, char **argv) {
    ALOGD("hello world!");
    defaultServiceManager()->addService(String16("test_server"), new Test());
    android::ProcessState::self()->startThreadPool();
    ALOGD("Demo service is now ready");
    IPCThreadState::self()->joinThreadPool();
    ALOGD("Demo service thread joined");
    return 0;
}

