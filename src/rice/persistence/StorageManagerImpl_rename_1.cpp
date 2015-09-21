// Generated from /pastry-2.1/src/rice/persistence/StorageManagerImpl.java
#include <rice/persistence/StorageManagerImpl_rename_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::StorageManagerImpl_rename_1::StorageManagerImpl_rename_1(StorageManagerImpl *StorageManagerImpl_this, ::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , StorageManagerImpl_this(StorageManagerImpl_this)
    , oldId(oldId)
    , newId(newId)
{
    clinit();
    ctor(continuation);
}

void rice::persistence::StorageManagerImpl_rename_1::receiveResult(::java::lang::Object* o)
{
    npc(StorageManagerImpl_this->storage)->rename(oldId, newId, parent);
}

java::lang::String* rice::persistence::StorageManagerImpl_rename_1::toString()
{
    return ::java::lang::StringBuilder().append(u"rename of "_j)->append(static_cast< ::java::lang::Object* >(oldId))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(newId))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::StorageManagerImpl_rename_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::StorageManagerImpl_rename_1::getClass0()
{
    return class_();
}

