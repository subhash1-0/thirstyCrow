// Generated from /pastry-2.1/src/rice/p2p/util/ImmutableSortedMap.java
#include <rice/p2p/util/ImmutableSortedMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>

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

rice::p2p::util::ImmutableSortedMap::ImmutableSortedMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::ImmutableSortedMap::ImmutableSortedMap(::java::util::SortedMap* map) 
    : ImmutableSortedMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(map);
}

void rice::p2p::util::ImmutableSortedMap::ctor(::java::util::SortedMap* map)
{
    super::ctor();
    this->map = map;
}

java::util::Comparator* rice::p2p::util::ImmutableSortedMap::comparator()
{
    return npc(map)->comparator();
}

java::util::SortedMap* rice::p2p::util::ImmutableSortedMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    return new ImmutableSortedMap(npc(map)->subMap(fromKey, toKey));
}

java::util::SortedMap* rice::p2p::util::ImmutableSortedMap::headMap(::java::lang::Object* toKey)
{
    return new ImmutableSortedMap(npc(map)->headMap(toKey));
}

java::util::SortedMap* rice::p2p::util::ImmutableSortedMap::tailMap(::java::lang::Object* fromKey)
{
    return new ImmutableSortedMap(npc(map)->tailMap(fromKey));
}

java::lang::Object* rice::p2p::util::ImmutableSortedMap::firstKey()
{
    return java_cast< ::java::lang::Object* >(npc(map)->firstKey());
}

java::lang::Object* rice::p2p::util::ImmutableSortedMap::lastKey()
{
    return java_cast< ::java::lang::Object* >(npc(map)->lastKey());
}

int32_t rice::p2p::util::ImmutableSortedMap::size()
{
    return npc(map)->size();
}

bool rice::p2p::util::ImmutableSortedMap::isEmpty()
{
    return npc(map)->isEmpty();
}

bool rice::p2p::util::ImmutableSortedMap::containsKey(::java::lang::Object* key)
{
    return npc(map)->containsKey(key);
}

bool rice::p2p::util::ImmutableSortedMap::containsValue(::java::lang::Object* value)
{
    return npc(map)->containsValue(value);
}

java::lang::Object* rice::p2p::util::ImmutableSortedMap::get(::java::lang::Object* key)
{
    return java_cast< ::java::lang::Object* >(npc(map)->get(key));
}

java::lang::Object* rice::p2p::util::ImmutableSortedMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    throw new ::java::lang::UnsupportedOperationException(u"put not supported by immutablemap"_j);
}

java::lang::Object* rice::p2p::util::ImmutableSortedMap::remove(::java::lang::Object* key)
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported by immutablemap"_j);
}

void rice::p2p::util::ImmutableSortedMap::putAll(::java::util::Map* t)
{
    throw new ::java::lang::UnsupportedOperationException(u"putall not supported by immutablemap"_j);
}

void rice::p2p::util::ImmutableSortedMap::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported by immutablemap"_j);
}

java::util::Set* rice::p2p::util::ImmutableSortedMap::keySet()
{
    return npc(map)->keySet();
}

java::util::Collection* rice::p2p::util::ImmutableSortedMap::values()
{
    return npc(map)->values();
}

java::util::Set* rice::p2p::util::ImmutableSortedMap::entrySet()
{
    return npc(map)->entrySet();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::ImmutableSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.ImmutableSortedMap", 32);
    return c;
}

bool rice::p2p::util::ImmutableSortedMap::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

int32_t rice::p2p::util::ImmutableSortedMap::hashCode()
{
    return Object::hashCode();
}

bool rice::p2p::util::ImmutableSortedMap::remove(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return super::remove(arg0, arg1);
}

java::lang::Class* rice::p2p::util::ImmutableSortedMap::getClass0()
{
    return class_();
}

