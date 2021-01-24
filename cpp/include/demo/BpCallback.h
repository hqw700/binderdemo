#ifndef AIDL_GENERATED_DEMO_BP_CALLBACK_H_
#define AIDL_GENERATED_DEMO_BP_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <demo/ICallback.h>

using namespace android;
namespace demo {

    class BpCallback : public BpInterface<ICallback> {
    public:
        explicit BpCallback(const sp<IBinder> &_aidl_impl);

        virtual ~BpCallback() = default;

        binder::Status onCallback(const String16 &str) override;
    };  // class BpCallback

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BP_CALLBACK_H_