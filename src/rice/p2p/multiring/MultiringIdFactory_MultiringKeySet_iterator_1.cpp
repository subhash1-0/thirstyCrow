// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory_MultiringKeySet_iterator_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringKeySet.hpp>
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

rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::MultiringIdFactory_MultiringKeySet_iterator_1(MultiringIdFactory_MultiringKeySet *MultiringIdFactory_MultiringKeySet_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdFactory_MultiringKeySet_this(MultiringIdFactory_MultiringKeySet_this)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::init()
{
    i = npc(MultiringIdFactory_MultiringKeySet_this->set)->iterator();
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::hasNext()
{
    return npc(i)->hasNext();
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::next()
{
    return npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(i)->next()))))->getId();
}

void rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::remove()
{
    npc(i)->remove();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet_iterator_1::getClass0()
{
    return class_();
}

