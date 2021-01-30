#include <demo/ITest.h>
#include <demo/BpTest.h>

using namespace android;

namespace demo {
    IMPLEMENT_META_INTERFACE(Test, "demo.ITest");
}  // namespace demo
#include <demo/BpTest.h>
#include <binder/Parcel.h>

namespace demo {

    BpTest::BpTest(const sp<IBinder> &_aidl_impl) : BpInterface<ITest>(_aidl_impl) {
    }

    binder::Status BpTest::ping() {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::PING, _aidl_data, &_aidl_reply);
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

    binder::Status BpTest::pingOneway() {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::PINGONEWAY, _aidl_data, &_aidl_reply,
                                              IBinder::FLAG_ONEWAY);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

    binder::Status BpTest::sendIn(const os::PersistableBundle &data) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeParcelable(data);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::SENDIN, _aidl_data, &_aidl_reply);
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

    binder::Status BpTest::sendOut(os::PersistableBundle *data) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::SENDOUT, _aidl_data, &_aidl_reply);
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
        _aidl_ret_status = _aidl_reply.readParcelable(data);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

    binder::Status BpTest::sendInOut(os::PersistableBundle *data) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeParcelable(*data);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::SENDINOUT, _aidl_data, &_aidl_reply);
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
        _aidl_ret_status = _aidl_reply.readParcelable(data);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

    binder::Status BpTest::sum(int32_t x, int32_t y, int32_t *_aidl_return) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeInt32(x);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeInt32(y);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::SUM, _aidl_data, &_aidl_reply);
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
        _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_error:
        _aidl_status.setFromStatusT(_aidl_ret_status);
        return _aidl_status;
    }

    binder::Status BpTest::registerCallback(const sp<::demo::ICallback> &cb) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeStrongBinder(::demo::ICallback::asBinder(cb));
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::REGISTERCALLBACK, _aidl_data, &_aidl_reply);
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

    binder::Status BpTest::unregisterCallback(const sp<::demo::ICallback> &cb) {
        Parcel _aidl_data;
        Parcel _aidl_reply;
        status_t _aidl_ret_status = OK;
        binder::Status _aidl_status;
        _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = _aidl_data.writeStrongBinder(::demo::ICallback::asBinder(cb));
        if (((_aidl_ret_status) != (OK))) {
            goto _aidl_error;
        }
        _aidl_ret_status = remote()->transact(ITest::UNREGISTERCALLBACK, _aidl_data, &_aidl_reply);
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
#include <demo/BnTest.h>
#include <binder/Parcel.h>

namespace demo {

    status_t BnTest::onTransact(uint32_t _aidl_code, const Parcel &_aidl_data, Parcel *_aidl_reply,
                       uint32_t _aidl_flags) {
        status_t _aidl_ret_status = OK;
        switch (_aidl_code) {
            case Call::PING: {
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                binder::Status _aidl_status(ping());
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
            }
                break;
            case Call::PINGONEWAY: {
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                binder::Status _aidl_status(pingOneway());
            }
                break;
            case Call::SENDIN: {
                os::PersistableBundle in_data;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readParcelable(&in_data);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(sendIn(in_data));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
            }
                break;
            case Call::SENDOUT: {
                os::PersistableBundle out_data;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                binder::Status _aidl_status(sendOut(&out_data));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
                _aidl_ret_status = _aidl_reply->writeParcelable(out_data);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
            }
                break;
            case Call::SENDINOUT: {
                os::PersistableBundle in_data;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readParcelable(&in_data);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(sendInOut(&in_data));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
                _aidl_ret_status = _aidl_reply->writeParcelable(in_data);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
            }
                break;
            case Call::SUM: {
                int32_t in_x;
                int32_t in_y;
                int32_t _aidl_return;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readInt32(&in_x);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                _aidl_ret_status = _aidl_data.readInt32(&in_y);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(sum(in_x, in_y, &_aidl_return));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
                _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
            }
                break;
            case Call::REGISTERCALLBACK: {
                sp<::demo::ICallback> in_cb;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readStrongBinder(&in_cb);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(registerCallback(in_cb));
                _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                if (!_aidl_status.isOk()) {
                    break;
                }
            }
                break;
            case Call::UNREGISTERCALLBACK: {
                sp<::demo::ICallback> in_cb;
                if (!(_aidl_data.checkInterface(this))) {
                    _aidl_ret_status = BAD_TYPE;
                    break;
                }
                _aidl_ret_status = _aidl_data.readStrongBinder(&in_cb);
                if (((_aidl_ret_status) != (OK))) {
                    break;
                }
                binder::Status _aidl_status(unregisterCallback(in_cb));
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
