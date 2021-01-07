#ifndef AIDL_GENERATED_DEMO_BN_TEST_H_
#define AIDL_GENERATED_DEMO_BN_TEST_H_

#include <binder/IInterface.h>
#include <demo/ITest.h>

namespace demo {

class BnTest : public ::android::BnInterface<ITest> {
public:
::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags = 0) override;
};  // class BnTest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BN_TEST_H_