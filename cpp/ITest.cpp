#include <demo/ITest.h>
#include <demo/BpTest.h>

namespace demo {
    IMPLEMENT_META_INTERFACE(Test, "demo.ITest");
}  // namespace demo
#include <demo/BpTest.h>
#include <binder/Parcel.h>

namespace demo {

    BpTest::BpTest(const ::android::sp<::android::IBinder> &_aidl_impl)
            : BpInterface<ITest>(_aidl_impl) {
    }

    ::android::binder::Status BpTest::ping() {
        ::android::Parcel _aidl_data;
        ::android::Parcel _aidl_reply;
        ::android::status_t _aidl_ret_status = ::android::OK;
        ::android::binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::PING, _aidl_data, &_aidl_reply);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        if (!_aidl_status.isOk()) {
            return _aidl_status;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

    ::android::binder::Status BpTest::sum(int32_t x, int32_t y, int32_t *_aidl_return) {
        ::android::Parcel _aidl_data;
        ::android::Parcel _aidl_reply;
        ::android::status_t _aidl_ret_status = ::android::OK;
        ::android::binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeInt32(x);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeInt32(y);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::SUM, _aidl_data, &_aidl_reply);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        if (!_aidl_status.isOk()) {
            return _aidl_status;
        }
        _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
        if (((_aidl_ret_status) != (::android::OK))) {
            goto _aidl_error;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

}  // namespace demo
#include <demo/BnTest.h>
#include <binder/Parcel.h>

namespace demo {

    ::android::status_t
    BnTest::onTransact(uint32_t _aidl_code, const ::android::Parcel &_aidl_data, ::android::Parcel *_aidl_reply,
                       uint32_t _aidl_flags) {
        ::android::status_t _aidl_ret_status = ::android::OK;
        switch (_aidl_code) {
            case Call::PING: {
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = ::android::BAD_TYPE;
                    break;
                }
                ::android::binder::Status _aidl_status(ping());
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (::android::OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
            }
                break;
            case Call::SUM: {
                int32_t in_x;
                int32_t in_y;
                int32_t _aidl_return;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = ::android::BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readInt32(&in_x);
                if (((_aidl_ret_status) != (::android::OK))) {
                    break;
                }
                _aidl_ret_status = _aidl_data.readInt32(&in_y);
                if (((_aidl_ret_status) != (::android::OK))) {
                    break;
                }
                ::android::binder::Status _aidl_status(sum(in_x, in_y, &_aidl_return));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (::android::OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
                _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
                if (((_aidl_ret_status) != (::android::OK))) {
                    break;
                }
            }
                break;
            default: {
                _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
            }
                break;
        }
        if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
            _aidl_ret_status = ::android::binder::Status::fromExceptionCode(
                    ::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
        }
        return _aidl_ret_status;
    }

}  // namespace demo
