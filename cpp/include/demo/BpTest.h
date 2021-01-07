#ifndef AIDL_GENERATED_DEMO_BP_TEST_H_
#define AIDL_GENERATED_DEMO_BP_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <demo/ITest.h>

namespace demo {

class BpTest : public ::android::BpInterface<ITest> {
public:
explicit BpTest(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpTest() = default;
::android::binder::Status ping() override;
::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) override;
};  // class BpTest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BP_TEST_H_