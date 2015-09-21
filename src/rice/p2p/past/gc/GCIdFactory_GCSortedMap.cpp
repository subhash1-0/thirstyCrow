// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java
#include <rice/p2p/past/gc/GCIdFactory_GCSortedMap.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/past/gc/GCIdFactory_GCEntrySet.hpp>
#include <rice/p2p/past/gc/GCIdFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCIdFactory_GCSortedMap::GCIdFactory_GCSortedMap(GCIdFactory *GCIdFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCIdFactory_this(GCIdFactory_this)
{
    clinit();
}

rice::p2p::past::gc::GCIdFactory_GCSortedMap::GCIdFactory_GCSortedMap(GCIdFactory *GCIdFactory_this, ::java::util::SortedMap* map) 
    : GCIdFactory_GCSortedMap(GCIdFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(map);
}

void rice::p2p::past::gc::GCIdFactory_GCSortedMap::ctor(::java::util::SortedMap* map)
{
    super::ctor();
    this->map = map;
}

java::util::Comparator* rice::p2p::past::gc::GCIdFactory_GCSortedMap::comparator()
{
    return nullptr;
}

java::lang::Object* rice::p2p::past::gc::GCIdFactory_GCSortedMap::firstKey()
{
    throw new ::java::lang::UnsupportedOperationException(u"firstKey not supported!"_j);
}

java::util::SortedMap* rice::p2p::past::gc::GCIdFactory_GCSortedMap::headMap(::java::lang::Object* toKey)
{
    throw new ::java::lang::UnsupportedOperationException(u"headMap not supported!"_j);
}

java::lang::Object* rice::p2p::past::gc::GCIdFactory_GCSortedMap::lastKey()
{
    throw new ::java::lang::UnsupportedOperationException(u"lastKey not supported!"_j);
}

java::util::SortedMap* rice::p2p::past::gc::GCIdFactory_GCSortedMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    throw new ::java::lang::UnsupportedOperationException(u"subMap not supported!"_j);
}

java::util::SortedMap* rice::p2p::past::gc::GCIdFactory_GCSortedMap::tailMap(::java::lang::Object* fromKey)
{
    throw new ::java::lang::UnsupportedOperationException(u"tailMap not supported!"_j);
}

void rice::p2p::past::gc::GCIdFactory_GCSortedMap::clear()
{
    throw new ::java::lang::UnsupportedOperationException(u"clear not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCSortedMap::containsKey(::java::lang::Object* key)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsKey not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCSortedMap::containsValue(::java::lang::Object* value)
{
    throw new ::java::lang::UnsupportedOperationException(u"containsValue not supported!"_j);
}

java::util::Set* rice::p2p::past::gc::GCIdFactory_GCSortedMap::entrySet()
{
    return new GCIdFactory_GCEntrySet(GCIdFactory_this, npc(map)->entrySet());
}

bool rice::p2p::past::gc::GCIdFactory_GCSortedMap::equals(::java::lang::Object* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"equals not supported!"_j);
}

java::lang::Object* rice::p2p::past::gc::GCIdFactory_GCSortedMap::get(::java::lang::Object* key)
{
    throw new ::java::lang::UnsupportedOperationException(u"get not supported!"_j);
}

int32_t rice::p2p::past::gc::GCIdFactory_GCSortedMap::hashCode()
{
    throw new ::java::lang::UnsupportedOperationException(u"hashCode not supported!"_j);
}

bool rice::p2p::past::gc::GCIdFactory_GCSortedMap::isEmpty()
{
    throw new ::java::lang::UnsupportedOperationException(u"isEmpty not supported!"_j);
}

java::util::Set* rice::p2p::past::gc::GCIdFactory_GCSortedMap::keySet()
{
    throw new ::java::lang::UnsupportedOperationException(u"keyset not supported!"_j);
}

java::lang::Object* rice::p2p::past::gc::GCIdFactory_GCSortedMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    throw new ::java::lang::UnsupportedOperationException(u"put not supported!"_j);
}

void rice::p2p::past::gc::GCIdFactory_GCSortedMap::putAll(::java::util::Map* t)
{
    throw new ::java::lang::UnsupportedOperationException(u"putAll not supported!"_j);
}

java::lang::Object* rice::p2p::past::gc::GCIdFactory_GCSortedMap::remove(::java::lang::Object* key)
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported!"_j);
}

int32_t rice::p2p::past::gc::GCIdFactory_GCSortedMap::size()
{
    return npc(map)->size();
}

java::util::Collection* rice::p2p::past::gc::GCIdFactory_GCSortedMap::values()
{
    throw new ::java::lang::UnsupportedOperationException(u"values not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdFactory_GCSortedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCIdFactory.GCSortedMap", 40);
    return c;
}

bool rice::p2p::past::gc::GCIdFactory_GCSortedMap::remove(::java::lang::Object* key, ::java::lang::Object* value)
{
    return super::remove(key, value);
}

java::lang::Class* rice::p2p::past::gc::GCIdFactory_GCSortedMap::getClass0()
{
    return class_();
}

