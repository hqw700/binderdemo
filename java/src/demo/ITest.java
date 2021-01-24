/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: frameworks/native/cmds/binderdemo/aidl/demo/ITest.aidl
 */
package demo;

public interface ITest extends android.os.IInterface {
    /**
     * Local-side IPC implementation stub class.
     */
    public static abstract class Stub extends android.os.Binder implements demo.ITest {
        private static final java.lang.String DESCRIPTOR = "demo.ITest";

        /**
         * Construct the stub at attach it to the interface.
         */
        public Stub() {
            this.attachInterface(this, DESCRIPTOR);
        }

        /**
         * Cast an IBinder object into an demo.ITest interface,
         * generating a proxy if needed.
         */
        public static demo.ITest asInterface(android.os.IBinder obj) {
            if ((obj == null)) {
                return null;
            }
            android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
            if (((iin != null) && (iin instanceof demo.ITest))) {
                return ((demo.ITest) iin);
            }
            return new demo.ITest.Stub.Proxy(obj);
        }

        @Override
        public android.os.IBinder asBinder() {
            return this;
        }

        @Override
        public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException {
            switch (code) {
                case INTERFACE_TRANSACTION: {
                    reply.writeString(DESCRIPTOR);
                    return true;
                }
                case TRANSACTION_ping: {
                    data.enforceInterface(DESCRIPTOR);
                    this.ping();
                    reply.writeNoException();
                    return true;
                }
                case TRANSACTION_sum: {
                    data.enforceInterface(DESCRIPTOR);
                    int _arg0;
                    _arg0 = data.readInt();
                    int _arg1;
                    _arg1 = data.readInt();
                    int _result = this.sum(_arg0, _arg1);
                    reply.writeNoException();
                    reply.writeInt(_result);
                    return true;
                }
                case TRANSACTION_registerCallback: {
                    data.enforceInterface(DESCRIPTOR);
                    demo.ICallback _arg0;
                    _arg0 = demo.ICallback.Stub.asInterface(data.readStrongBinder());
                    this.registerCallback(_arg0);
                    reply.writeNoException();
                    return true;
                }
                case TRANSACTION_unregisterCallback: {
                    data.enforceInterface(DESCRIPTOR);
                    demo.ICallback _arg0;
                    _arg0 = demo.ICallback.Stub.asInterface(data.readStrongBinder());
                    this.unregisterCallback(_arg0);
                    reply.writeNoException();
                    return true;
                }
            }
            return super.onTransact(code, data, reply, flags);
        }

        private static class Proxy implements demo.ITest {
            private android.os.IBinder mRemote;

            Proxy(android.os.IBinder remote) {
                mRemote = remote;
            }

            @Override
            public android.os.IBinder asBinder() {
                return mRemote;
            }

            public java.lang.String getInterfaceDescriptor() {
                return DESCRIPTOR;
            }

            @Override
            public void ping() throws android.os.RemoteException {
                android.os.Parcel _data = android.os.Parcel.obtain();
                android.os.Parcel _reply = android.os.Parcel.obtain();
                try {
                    _data.writeInterfaceToken(DESCRIPTOR);
                    mRemote.transact(Stub.TRANSACTION_ping, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override
            public int sum(int x, int y) throws android.os.RemoteException {
                android.os.Parcel _data = android.os.Parcel.obtain();
                android.os.Parcel _reply = android.os.Parcel.obtain();
                int _result;
                try {
                    _data.writeInterfaceToken(DESCRIPTOR);
                    _data.writeInt(x);
                    _data.writeInt(y);
                    mRemote.transact(Stub.TRANSACTION_sum, _data, _reply, 0);
                    _reply.readException();
                    _result = _reply.readInt();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
                return _result;
            }

            @Override
            public void registerCallback(demo.ICallback cb) throws android.os.RemoteException {
                android.os.Parcel _data = android.os.Parcel.obtain();
                android.os.Parcel _reply = android.os.Parcel.obtain();
                try {
                    _data.writeInterfaceToken(DESCRIPTOR);
                    _data.writeStrongBinder((((cb != null)) ? (cb.asBinder()) : (null)));
                    mRemote.transact(Stub.TRANSACTION_registerCallback, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }

            @Override
            public void unregisterCallback(demo.ICallback cb) throws android.os.RemoteException {
                android.os.Parcel _data = android.os.Parcel.obtain();
                android.os.Parcel _reply = android.os.Parcel.obtain();
                try {
                    _data.writeInterfaceToken(DESCRIPTOR);
                    _data.writeStrongBinder((((cb != null)) ? (cb.asBinder()) : (null)));
                    mRemote.transact(Stub.TRANSACTION_unregisterCallback, _data, _reply, 0);
                    _reply.readException();
                } finally {
                    _reply.recycle();
                    _data.recycle();
                }
            }
        }

        static final int TRANSACTION_ping = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
        static final int TRANSACTION_sum = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
        static final int TRANSACTION_registerCallback = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
        static final int TRANSACTION_unregisterCallback = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    }

    public void ping() throws android.os.RemoteException;

    public int sum(int x, int y) throws android.os.RemoteException;

    public void registerCallback(demo.ICallback cb) throws android.os.RemoteException;

    public void unregisterCallback(demo.ICallback cb) throws android.os.RemoteException;
}
