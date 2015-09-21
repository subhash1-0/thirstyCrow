// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdSet.java
#include <rice/p2p/past/gc/GCIdSet_getIterator_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>

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

rice::p2p::past::gc::GCIdSet_getIterator_1::GCIdSet_getIterator_1(GCIdSet *GCIdSet_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCIdSet_this(GCIdSet_this)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::past::gc::GCIdSet_getIterator_1::init()
{
    i = npc(GCIdSet_this->ids)->getIterator();
}

bool rice::p2p::past::gc::GCIdSet_getIterator_1::hasNext()
{
    return npc(i)->hasNext();
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCIdSet_getIterator_1::next()
{
    return GCIdSet_this->getGCId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next())));
}

void rice::p2p::past::gc::GCIdSet_getIterator_1::remove()
{
    throw new ::java::lang::UnsupportedOperationException(u"Remove on GCIdSet()!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdSet_getIterator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCIdSet_getIterator_1::getClass0()
{
    return class_();
}

