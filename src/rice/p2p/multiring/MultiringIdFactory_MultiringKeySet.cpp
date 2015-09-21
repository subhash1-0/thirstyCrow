// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory_MultiringKeySet.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/lang/reflect/Array_.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringKeySet_iterator_1.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::MultiringIdFactory_MultiringKeySet(MultiringIdFactory *MultiringIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdFactory_this(MultiringIdFactory_this)
{
    clinit();
}

rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::MultiringIdFactory_MultiringKeySet(MultiringIdFactory *MultiringIdFactory_this, ::java::util::Set* set) 
    : MultiringIdFactory_MultiringKeySet(MultiringIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(set);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::ctor(::java::util::Set* set)
{
    super::ctor();
    this->set = set;
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::add(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"add not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::addAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"addAll not supported!"_j);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::contains(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"contains not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::containsAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsAll not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::isEmpty()
{
    throw new ::java::lang::UnsupportedOperationException(u"isEmpty not supported!"_j);
}

java::util::Iterator* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::iterator()
{
    return new MultiringIdFactory_MultiringKeySet_iterator_1(this);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::remove(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::removeAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"removeAll not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::retainAll(::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"retainAll not supported!"_j);
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::size()
{
    throw new ::java::lang::UnsupportedOperationException(u"size not supported!"_j);
}

java::lang::ObjectArray* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::toArray_()
{
    auto result = new ::java::lang::ObjectArray(npc(set)->size());
    auto i = npc(set)->iterator();
    auto j = int32_t(0);
    while (npc(i)->hasNext()) 
                result->set(j++, npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(i)->next()))))->getId());

    return result;
}

java::lang::ObjectArray* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::toArray_(::java::lang::ObjectArray* a)
{
    auto result = java_cast< ::java::lang::ObjectArray* >(::java::lang::reflect::Array_::newInstance(static_cast< ::java::lang::Class* >(npc(npc(a)->getClass())->getComponentType()), npc(set)->size()));
    auto i = npc(set)->iterator();
    auto j = int32_t(0);
    while (npc(i)->hasNext()) 
                result->set(j++, npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(i)->next()))))->getId());

    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdFactory.MultiringKeySet", 53);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringKeySet::getClass0()
{
    return class_();
}

