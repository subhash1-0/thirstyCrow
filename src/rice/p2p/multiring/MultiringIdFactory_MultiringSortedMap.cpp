// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java
#include <rice/p2p/multiring/MultiringIdFactory_MultiringSortedMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringEntrySet.hpp>
#include <rice/p2p/multiring/MultiringIdFactory_MultiringKeySet.hpp>
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

rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::MultiringIdFactory_MultiringSortedMap(MultiringIdFactory *MultiringIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringIdFactory_this(MultiringIdFactory_this)
{
    clinit();
}

rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::MultiringIdFactory_MultiringSortedMap(MultiringIdFactory *MultiringIdFactory_this, ::java::util::SortedMap* map) 
    : MultiringIdFactory_MultiringSortedMap(MultiringIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(map);
}

void rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::ctor(::java::util::SortedMap* map)
{
    super::ctor();
    this->map = map;
}

java::util::Comparator* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::comparator()
{
    return nullptr;
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::firstKey()
{
    return (java_cast< ::java::lang::Object* >(npc(map)->firstKey()) == nullptr ? static_cast< ::java::lang::Object* >(nullptr) : static_cast< ::java::lang::Object* >(npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(map)->firstKey()))))->getId()));
}

java::util::SortedMap* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::headMap(::java::lang::Object* toKey)
{
    return npc(map)->headMap(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(toKey)));
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::lastKey()
{
    return (java_cast< ::java::lang::Object* >(npc(map)->lastKey()) == nullptr ? static_cast< ::java::lang::Object* >(nullptr) : static_cast< ::java::lang::Object* >(npc((java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(map)->lastKey()))))->getId()));
}

java::util::SortedMap* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    return npc(map)->subMap(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(fromKey)), RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(toKey)));
}

java::util::SortedMap* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::tailMap(::java::lang::Object* fromKey)
{
    return npc(map)->tailMap(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(fromKey)));
}

void rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::containsKey(::java::lang::Object* key)
{
    return npc(map)->containsKey(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(key)));
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::containsValue(::java::lang::Object* value)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsValue not supported!"_j);
}

java::util::Set* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::entrySet()
{
    return new MultiringIdFactory_MultiringEntrySet(MultiringIdFactory_this, npc(map)->entrySet());
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::get(::java::lang::Object* key)
{
    throw new ::java::lang::UnsupportedOperationException(u"get not supported!"_j);
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::isEmpty()
{
    throw new ::java::lang::UnsupportedOperationException(u"isEmpty not supported!"_j);
}

java::util::Set* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::keySet()
{
    return new MultiringIdFactory_MultiringKeySet(MultiringIdFactory_this, npc(map)->keySet());
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    return java_cast< ::java::lang::Object* >(npc(map)->put(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(key)), value));
}

void rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::putAll(::java::util::Map* t)
{
    throw new ::java::lang::UnsupportedOperationException(u"putAll not supported!"_j);
}

java::lang::Object* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::remove(::java::lang::Object* key)
{
    return java_cast< ::java::lang::Object* >(npc(map)->remove(RingId::build(MultiringIdFactory_this->ringId, java_cast< ::rice::p2p::commonapi::Id* >(key))));
}

int32_t rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::size()
{
    return npc(map)->size();
}

java::util::Collection* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::values()
{
    throw new ::java::lang::UnsupportedOperationException(u"values not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdFactory.MultiringSortedMap", 56);
    return c;
}

bool rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return super::remove(arg0, arg1);
}

java::lang::Class* rice::p2p::multiring::MultiringIdFactory_MultiringSortedMap::getClass0()
{
    return class_();
}

