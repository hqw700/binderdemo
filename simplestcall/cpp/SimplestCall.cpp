#define LOG_TAG "simplest_call"

#include <stdlib.h>

#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>
#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

using namespace android;

// get the name of the generic interface we hold a reference to
static String16 get_interface_name(sp<IBinder> service)
{
    if (service != nullptr) {
        Parcel data, reply;
        status_t err = service->transact(IBinder::INTERFACE_TRANSACTION, data, &reply);
        if (err == NO_ERROR) {
            return reply.readString16();
        }
    }
    return String16();
}

int main(int argc, char* const argv[]) {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> service = sm->checkService(String16("test_server"));
    // Not necessary function, can be replaced with ifName = "demo.ITest"
    String16 ifName = get_interface_name(service);

    if (service != nullptr && ifName.size() > 0) {
        Parcel data, reply;
        // the interface name is first
        data.writeInterfaceToken(ifName);
        // ping
        service->transact(IBinder::FIRST_CALL_TRANSACTION + 0, data, &reply);
        aout << "Result: " << reply << endl;
    }
}