// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache_flush_5.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/Continuation.hpp>
#include <rice/persistence/LRUCache.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::LRUCache_flush_5::LRUCache_flush_5(LRUCache *LRUCache_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCache_this(LRUCache_this)
{
    clinit();
    ctor(continuation);
}

void rice::persistence::LRUCache_flush_5::receiveResult(::java::lang::Object* o)
{
    npc(LRUCache_this->order)->clear();
    npc(parent)->receiveResult(::java::lang::Boolean::TRUE());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache_flush_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::LRUCache_flush_5::getClass0()
{
    return class_();
}

