// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache_setMaximumSize_3.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/persistence/LRUCache.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::LRUCache_setMaximumSize_3::LRUCache_setMaximumSize_3(LRUCache *LRUCache_this, int32_t size, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCache_this(LRUCache_this)
    , size(size)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::LRUCache_setMaximumSize_3::receiveResult(::java::lang::Object* o)
{
    LRUCache_this->maximumSize = size;
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::LRUCache_setMaximumSize_3::receiveException(::java::lang::Exception* e)
{
    npc(c)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache_setMaximumSize_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::LRUCache_setMaximumSize_3::getClass0()
{
    return class_();
}

