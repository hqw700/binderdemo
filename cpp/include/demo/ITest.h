#ifndef AIDL_GENERATED_DEMO_I_TEST_H_
#define AIDL_GENERATED_DEMO_I_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/PersistableBundle.h>
#include <binder/Status.h>
#include <cstdint>
#include <demo/ICallback.h>
#include <utils/StrongPointer.h>

using namespace android;
namespace demo {
    class ITest : public IInterface {
    public:
        DECLARE_META_INTERFACE(Test);

        virtual binder::Status ping() = 0;

        virtual binder::Status pingOneway() = 0;

        virtual binder::Status sendIn(const os::PersistableBundle &data) = 0;

        virtual binder::Status sendOut(os::PersistableBundle *data) = 0;

        virtual binder::Status sendInOut(os::PersistableBundle *data) = 0;

        virtual binder::Status sum(int32_t x, int32_t y, int32_t *_aidl_return) = 0;

        virtual binder::Status registerCallback(const sp<::demo::ICallback> &cb) = 0;

        virtual binder::Status unregisterCallback(const sp<::demo::ICallback> &cb) = 0;

        enum Call {
            PING = IBinder::FIRST_CALL_TRANSACTION + 0,
            PINGONEWAY = IBinder::FIRST_CALL_TRANSACTION + 1,
            SENDIN = IBinder::FIRST_CALL_TRANSACTION + 2,
            SENDOUT = IBinder::FIRST_CALL_TRANSACTION + 3,
            SENDINOUT = IBinder::FIRST_CALL_TRANSACTION + 4,
            SUM = IBinder::FIRST_CALL_TRANSACTION + 5,
            REGISTERCALLBACK = IBinder::FIRST_CALL_TRANSACTION + 6,
            UNREGISTERCALLBACK = IBinder::FIRST_CALL_TRANSACTION + 7,
        };
    };  // class ITest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_I_TEST_H_