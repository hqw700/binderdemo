#ifndef AIDL_GENERATED_DEMO_BP_TEST_H_
#define AIDL_GENERATED_DEMO_BP_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <demo/ITest.h>

using namespace android;

namespace demo {

    class BpTest : public BpInterface<ITest> {
    public:
        explicit BpTest(const sp<IBinder> &_aidl_impl);

        virtual ~BpTest() = default;

        binder::Status ping() override;

        binder::Status sum(int32_t x, int32_t y, int32_t *_aidl_return) override;
    };  // class BpTest

}  // namespace demo

#endif  // AIDL_GENERATED_DEMO_BP_TEST_H_