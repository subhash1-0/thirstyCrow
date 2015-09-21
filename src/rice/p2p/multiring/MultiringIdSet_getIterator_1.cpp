// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdSet.java
#include <rice/p2p/multiring/MultiringIdSet_getIterator_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/multiring/MultiringIdSet.hpp>
#include <rice/p2p/multiring/RingId.hpp>

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

rice::p2p::multiring::MultiringIdSet_getIterator_1::MultiringIdSet_getIterator_1(MultiringIdSet *MultiringIdSet_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdSet_this(MultiringIdSet_this)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::multiring::MultiringIdSet_getIterator_1::init()
{
    i = npc(MultiringIdSet_this->set)->getIterator();
}

bool rice::p2p::multiring::MultiringIdSet_getIterator_1::hasNext()
{
    return npc(i)->hasNext();
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringIdSet_getIterator_1::next()
{
    return RingId::build(MultiringIdSet_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next())));
}

void rice::p2p::multiring::MultiringIdSet_getIterator_1::remove()
{
    npc(i)->remove();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdSet_getIterator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdSet_getIterator_1::getClass0()
{
    return class_();
}

