#ifndef AIDL_GENERATED_DEMO_I_CALLBACK_H_
#define AIDL_GENERATED_DEMO_I_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

using namespace android;
namespace demo {

    class ICallback : public IInterface {
    public:
        DECLARE_META_INTERFACE(Callback);

        virtual binder::Status onCallback(const String16 &str) = 0;

        enum Call {
            ONCALLBACK = IBinder::FIRST_CALL_TRANSACTION + 0,
        };
    };  // class ICallback

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_I_CALLBACK_H_