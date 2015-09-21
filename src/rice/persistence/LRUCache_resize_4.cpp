// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache_resize_4.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/Storage.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::LRUCache_resize_4::LRUCache_resize_4(LRUCache *LRUCache_this, int32_t size, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCache_this(LRUCache_this)
    , size(size)
{
    clinit();
    init();
    ctor(continuation);
}

void rice::persistence::LRUCache_resize_4::init()
{
    waitingForSize = true;
}

void rice::persistence::LRUCache_resize_4::receiveResult(::java::lang::Object* o)
{
    if(npc(LRUCache_this->storage)->getTotalSize() > size) {
        LRUCache_this->uncache(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(LRUCache_this->order)->getLast())), static_cast< ::rice::Continuation* >(this));
    } else {
        npc(parent)->receiveResult(new ::java::lang::Boolean(true));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache_resize_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::LRUCache_resize_4::getClass0()
{
    return class_();
}

