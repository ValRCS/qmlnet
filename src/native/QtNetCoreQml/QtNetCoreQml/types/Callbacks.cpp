#include <QtNetCoreQml/types/Callbacks.h>
#include <iostream>

typedef bool (*isTypeValidCb)(LPWSTR typeName);
typedef void (*buildTypeInfoCb)(NetTypeInfoContainer* typeInfo);

void buildTypeInfo(QSharedPointer<NetTypeInfo> typeInfo);

struct NetTypeInfoManagerCallbacks {
    isTypeValidCb isTypeValid;
    buildTypeInfoCb buildTypeInfo;
};

static NetTypeInfoManagerCallbacks sharedCallbacks;

bool isTypeValid(QString type) {
    return sharedCallbacks.isTypeValid((LPWSTR)type.utf16());
}

void buildTypeInfo(QSharedPointer<NetTypeInfo> typeInfo) {
    NetTypeInfoContainer* container = new NetTypeInfoContainer();
    container->netTypeInfo = typeInfo;
    sharedCallbacks.buildTypeInfo(container);
}

extern "C" {

void type_info_callbacks_registerCallbacks(NetTypeInfoManagerCallbacks* callbacks) {
    sharedCallbacks = *callbacks;
}

bool type_info_callbacks_isTypeValid(LPWSTR typeName) {
    return sharedCallbacks.isTypeValid(typeName);
}

void type_info_callbacks_buildTypeInfo(NetTypeInfoContainer* typeInfo) {
    sharedCallbacks.buildTypeInfo(typeInfo);
}

}