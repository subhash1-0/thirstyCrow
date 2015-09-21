// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory_MultiringMapEntry.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Map_Entry.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
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

rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::MultiringIdFactory_MultiringMapEntry(MultiringIdFactory *MultiringIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdFactory_this(MultiringIdFactory_this)
{
    clinit();
}

rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::MultiringIdFactory_MultiringMapEntry(MultiringIdFactory *MultiringIdFactory_this, ::java::util::Map_Entry* entry) 
    : MultiringIdFactory_MultiringMapEntry(MultiringIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(entry);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::ctor(::java::util::Map_Entry* entry)
{
    super::ctor();
    this->entry = entry;
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::getKey()
{
    return npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(entry)->getKey()))))->getId();
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::getValue()
{
    return java_cast< ::java::lang::Object* >(npc(entry)->getValue());
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::setValue(::java::lang::Object* value)
{
    throw new ::java::lang::UnsupportedOperationException(u"setValue not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdFactory.MultiringMapEntry", 55);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry::getClass0()
{
    return class_();
}

