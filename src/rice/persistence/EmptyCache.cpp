// Generated from /pastry-2.1/src/rice/persistence/EmptyCache.java
#include <rice/persistence/EmptyCache.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::EmptyCache::EmptyCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::EmptyCache::EmptyCache(::rice::p2p::commonapi::IdFactory* factory) 
    : EmptyCache(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

void rice::persistence::EmptyCache::ctor(::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->factory = factory;
}

void rice::persistence::EmptyCache::rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c)
{
    npc(c)->receiveException(new ::java::lang::IllegalArgumentException(u"EmptyCache has no objects!"_j));
}

void rice::persistence::EmptyCache::cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::EmptyCache::uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

bool rice::persistence::EmptyCache::exists(::rice::p2p::commonapi::Id* id)
{
    return false;
}

void rice::persistence::EmptyCache::getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(c)->receiveResult(nullptr);
}

java::io::Serializable* rice::persistence::EmptyCache::getMetadata(::rice::p2p::commonapi::Id* id)
{
    return nullptr;
}

void rice::persistence::EmptyCache::setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* c)
{
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

rice::p2p::commonapi::IdSet* rice::persistence::EmptyCache::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(factory)->buildIdSet();
}

rice::p2p::commonapi::IdSet* rice::persistence::EmptyCache::scan()
{
    return npc(factory)->buildIdSet();
}

java::util::SortedMap* rice::persistence::EmptyCache::scanMetadata(::rice::p2p::commonapi::IdRange* range)
{
    return new ::rice::p2p::util::RedBlackMap();
}

java::util::SortedMap* rice::persistence::EmptyCache::scanMetadata()
{
    return new ::rice::p2p::util::RedBlackMap();
}

java::util::SortedMap* rice::persistence::EmptyCache::scanMetadataValuesHead(::java::lang::Object* value)
{
    return new ::rice::p2p::util::RedBlackMap();
}

java::util::SortedMap* rice::persistence::EmptyCache::scanMetadataValuesNull()
{
    return new ::rice::p2p::util::RedBlackMap();
}

int64_t rice::persistence::EmptyCache::getMaximumSize()
{
    return 0;
}

int64_t rice::persistence::EmptyCache::getTotalSize()
{
    return 0;
}

int32_t rice::persistence::EmptyCache::getSize()
{
    return 0;
}

void rice::persistence::EmptyCache::setMaximumSize(int32_t size, ::rice::Continuation* c)
{
    npc(c)->receiveResult(::java::lang::Boolean::TRUE());
}

void rice::persistence::EmptyCache::flush(::rice::Continuation* c)
{
    npc(c)->receiveResult(::java::lang::Boolean::TRUE());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::EmptyCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.EmptyCache", 27);
    return c;
}

java::lang::Class* rice::persistence::EmptyCache::getClass0()
{
    return class_();
}

