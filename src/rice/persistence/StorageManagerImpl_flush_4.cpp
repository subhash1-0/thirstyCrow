// Generated from /pastry-2.1/src/rice/persistence/StorageManagerImpl.java
#include <rice/persistence/StorageManagerImpl_flush_4.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::StorageManagerImpl_flush_4::StorageManagerImpl_flush_4(StorageManagerImpl *StorageManagerImpl_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , StorageManagerImpl_this(StorageManagerImpl_this)
{
    clinit();
    ctor(continuation);
}

void rice::persistence::StorageManagerImpl_flush_4::receiveResult(::java::lang::Object* o)
{
    npc(StorageManagerImpl_this->storage)->flush(parent);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::StorageManagerImpl_flush_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::StorageManagerImpl_flush_4::getClass0()
{
    return class_();
}

