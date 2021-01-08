#ifndef AIDL_GENERATED_DEMO_BN_TEST_H_
#define AIDL_GENERATED_DEMO_BN_TEST_H_

#include <binder/IInterface.h>
#include <demo/ITest.h>

using namespace android;
namespace demo {

    class BnTest : public BnInterface<ITest> {
    public:
        status_t onTransact(uint32_t _aidl_code, const Parcel &_aidl_data, Parcel *_aidl_reply,
                            uint32_t _aidl_flags = 0) override;
    };  // class BnTest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BN_TEST_H_