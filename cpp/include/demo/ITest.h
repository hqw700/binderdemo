#ifndef AIDL_GENERATED_DEMO_I_TEST_H_
#define AIDL_GENERATED_DEMO_I_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

using namespace android;
namespace demo {
    class ITest : public IInterface {
    public:
        DECLARE_META_INTERFACE(Test);

        virtual binder::Status ping() = 0;

        virtual binder::Status sum(int32_t x, int32_t y, int32_t *_aidl_return) = 0;

        enum Call {
            PING = IBinder::FIRST_CALL_TRANSACTION + 0,
            SUM = IBinder::FIRST_CALL_TRANSACTION + 1,
        };
    };  // class ITest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_I_TEST_H_