#include <demo/ICallback.h>
#include <demo/BpCallback.h>

using namespace android;
namespace demo {

    IMPLEMENT_META_INTERFACE(Callback, "demo.ICallback");

}  // namespace demo
#include <demo/BpCallback.h>
#include <binder/Parcel.h>

namespace demo {

    BpCallback::BpCallback(const sp<IBinder> &_aidl_impl)
            : BpInterface<ICallback>(_aidl_impl) {
    }

    binder::Status BpCallback::onCallback(const String16 &str) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeString16(str);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ICallback::ONCALLBACK, _aidl_data, &_aidl_reply);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        if (!_aidl_status.isOk()) {
            return _aidl_status;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

}  // namespace demo
#include <demo/BnCallback.h>
#include <binder/Parcel.h>

namespace demo {

    status_t
    BnCallback::onTransact(uint32_t _aidl_code, const Parcel &_aidl_data, Parcel *_aidl_reply,
                           uint32_t _aidl_flags) {
        status_t _aidl_ret_status = OK;
        switch (_aidl_code) {
            case Call::ONCALLBACK: {
                String16 in_str;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readString16(&in_str);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(onCallback(in_str));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
            }
                break;
            default: {
                _aidl_ret_status = BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
            }
                break;
        }
        if (_aidl_ret_status == UNEXPECTED_NULL) {
            _aidl_ret_status = binder::Status::fromExceptionCode(
                    binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
        }
        return _aidl_ret_status;
    }

}  // namespace demo
