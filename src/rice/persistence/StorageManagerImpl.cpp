// Generated from /pastry-2.1/src/rice/persistence/StorageManagerImpl.java
#include <rice/persistence/StorageManagerImpl.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManagerImpl_flush_4.hpp>
#include <rice/persistence/StorageManagerImpl_rename_1.hpp>
#include <rice/persistence/StorageManagerImpl_getObject_2.hpp>
#include <rice/persistence/StorageManagerImpl_setMetadata_3.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::StorageManagerImpl::StorageManagerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::StorageManagerImpl::StorageManagerImpl(::rice::p2p::commonapi::IdFactory* factory, Storage* storage, Cache* cache) 
    : StorageManagerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,storage,cache);
}

void rice::persistence::StorageManagerImpl::ctor(::rice::p2p::commonapi::IdFactory* factory, Storage* storage, Cache* cache)
{
    super::ctor();
    this->factory = factory;
    this->storage = storage;
    this->cache_ = cache;
}

rice::persistence::Storage* rice::persistence::StorageManagerImpl::getStorage()
{
    return storage;
}

rice::persistence::Cache* rice::persistence::StorageManagerImpl::getCache()
{
    return cache_;
}

bool rice::persistence::StorageManagerImpl::exists(::rice::p2p::commonapi::Id* id)
{
    return npc(storage)->exists(id);
}

void rice::persistence::StorageManagerImpl::rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c)
{
    npc(cache_)->rename(oldId, newId, new StorageManagerImpl_rename_1(this, oldId, newId, c));
}

void rice::persistence::StorageManagerImpl::getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(cache_)->getObject(id, new StorageManagerImpl_getObject_2(this, id, c));
}

java::io::Serializable* rice::persistence::StorageManagerImpl::getMetadata(::rice::p2p::commonapi::Id* id)
{
    return npc(storage)->getMetadata(id);
}

void rice::persistence::StorageManagerImpl::setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command)
{
    npc(cache_)->setMetadata(id, metadata, new StorageManagerImpl_setMetadata_3(this, id, metadata, command));
}

rice::p2p::commonapi::IdSet* rice::persistence::StorageManagerImpl::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(storage)->scan(range);
}

rice::p2p::commonapi::IdSet* rice::persistence::StorageManagerImpl::scan()
{
    return npc(storage)->scan();
}

java::util::SortedMap* rice::persistence::StorageManagerImpl::scanMetadata(::rice::p2p::commonapi::IdRange* range)
{
    return npc(storage)->scanMetadata(range);
}

java::util::SortedMap* rice::persistence::StorageManagerImpl::scanMetadata()
{
    return npc(storage)->scanMetadata();
}

java::util::SortedMap* rice::persistence::StorageManagerImpl::scanMetadataValuesHead(::java::lang::Object* value)
{
    return npc(storage)->scanMetadataValuesHead(value);
}

java::util::SortedMap* rice::persistence::StorageManagerImpl::scanMetadataValuesNull()
{
    return npc(storage)->scanMetadataValuesNull();
}

int64_t rice::persistence::StorageManagerImpl::getTotalSize()
{
    return npc(cache_)->getTotalSize() + npc(storage)->getTotalSize();
}

int32_t rice::persistence::StorageManagerImpl::getSize()
{
    return npc(storage)->getSize();
}

void rice::persistence::StorageManagerImpl::store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    npc(storage)->store(id, metadata, obj, c);
}

void rice::persistence::StorageManagerImpl::unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(storage)->unstore(id, c);
}

void rice::persistence::StorageManagerImpl::cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    npc(cache_)->cache(id, metadata, obj, c);
}

void rice::persistence::StorageManagerImpl::uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(cache_)->uncache(id, c);
}

int64_t rice::persistence::StorageManagerImpl::getMaximumSize()
{
    return npc(cache_)->getMaximumSize();
}

void rice::persistence::StorageManagerImpl::setMaximumSize(int32_t size, ::rice::Continuation* c)
{
    npc(cache_)->setMaximumSize(size, c);
}

void rice::persistence::StorageManagerImpl::flush(::rice::Continuation* c)
{
    npc(cache_)->flush(new StorageManagerImpl_flush_4(this, c));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::StorageManagerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.StorageManagerImpl", 35);
    return c;
}

java::lang::Class* rice::persistence::StorageManagerImpl::getClass0()
{
    return class_();
}

