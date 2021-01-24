#ifndef AIDL_GENERATED_DEMO_BN_CALLBACK_H_
#define AIDL_GENERATED_DEMO_BN_CALLBACK_H_

#include <binder/IInterface.h>
#include <demo/ICallback.h>

using namespace android;
namespace demo {

    class BnCallback : public BnInterface<ICallback> {
    public:
        status_t onTransact(uint32_t _aidl_code, const Parcel &_aidl_data, Parcel *_aidl_reply,
                            uint32_t _aidl_flags = 0) override;
    };  // class BnCallback

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BN_CALLBACK_H_