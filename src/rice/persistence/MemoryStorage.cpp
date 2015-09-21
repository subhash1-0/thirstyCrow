// Generated from /pastry-2.1/src/rice/persistence/MemoryStorage.java
#include <rice/persistence/MemoryStorage.hpp>

#include <java/io/BufferedOutputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/util/ImmutableSortedMap.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
#include <rice/p2p/util/ReverseTreeMap.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <Array.hpp>

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

rice::persistence::MemoryStorage::MemoryStorage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::MemoryStorage::MemoryStorage(::rice::p2p::commonapi::IdFactory* factory) 
    : MemoryStorage(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

void rice::persistence::MemoryStorage::ctor(::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->factory = factory;
    idSet = npc(factory)->buildIdSet();
    storage = new ::java::util::HashMap();
    metadata = new ::rice::p2p::util::ReverseTreeMap();
    currentSize = 0;
}

void rice::persistence::MemoryStorage::flush(::rice::Continuation* c)
{
    storage = new ::java::util::HashMap();
    metadata = new ::rice::p2p::util::ReverseTreeMap();
    idSet = npc(factory)->buildIdSet();
    currentSize = 0;
    npc(c)->receiveResult(::java::lang::Boolean::TRUE());
}

void rice::persistence::MemoryStorage::rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c)
{
    if(!npc(idSet)->isMemberId(oldId)) {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
        return;
    }
    npc(idSet)->removeId(oldId);
    npc(idSet)->addId(newId);
    npc(storage)->put(static_cast< ::java::lang::Object* >(newId), static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(storage)->get(static_cast< ::java::lang::Object* >(oldId)))));
    npc(storage)->remove(static_cast< ::java::lang::Object* >(oldId));
    npc(metadata)->put(newId, npc(metadata)->get(oldId));
    npc(metadata)->remove(oldId);
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::MemoryStorage::store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    if(id == nullptr || obj == nullptr) {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
        return;
    }
    currentSize += getSize(obj);
    npc(this->storage)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(obj));
    npc(this->metadata)->put(id, metadata);
    npc(idSet)->addId(id);
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::MemoryStorage::unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    auto stored = java_cast< ::java::lang::Object* >(npc(storage)->remove(static_cast< ::java::lang::Object* >(id)));
    npc(metadata)->remove(id);
    npc(idSet)->removeId(id);
    if(stored != nullptr) {
        currentSize -= getSize(stored);
        npc(c)->receiveResult(new ::java::lang::Boolean(true));
    } else {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
    }
}

bool rice::persistence::MemoryStorage::exists(::rice::p2p::commonapi::Id* id)
{
    return npc(storage)->containsKey(static_cast< ::java::lang::Object* >(id));
}

java::io::Serializable* rice::persistence::MemoryStorage::getMetadata(::rice::p2p::commonapi::Id* id)
{
    return java_cast< ::java::io::Serializable* >(npc(metadata)->get(id));
}

void rice::persistence::MemoryStorage::setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command)
{
    if(exists(id))
        npc(this->metadata)->put(id, metadata);

    npc(command)->receiveResult(new ::java::lang::Boolean(exists(id)));
}

void rice::persistence::MemoryStorage::getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    npc(c)->receiveResult(java_cast< ::java::lang::Object* >(npc(storage)->get(static_cast< ::java::lang::Object* >(id))));
}

rice::p2p::commonapi::IdSet* rice::persistence::MemoryStorage::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(idSet)->subSet(range);
}

rice::p2p::commonapi::IdSet* rice::persistence::MemoryStorage::scan()
{
    return idSet;
}

java::util::SortedMap* rice::persistence::MemoryStorage::scanMetadata(::rice::p2p::commonapi::IdRange* range)
{
    if(npc(range)->isEmpty())
        return new ::rice::p2p::util::RedBlackMap();
    else if(npc(npc(range)->getCCWId())->equals(npc(range)->getCWId()))
        return scanMetadata();
    else
        return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keySubMap(npc(range)->getCCWId(), npc(range)->getCWId()));
}

java::util::SortedMap* rice::persistence::MemoryStorage::scanMetadata()
{
    return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->keyMap());
}

java::util::SortedMap* rice::persistence::MemoryStorage::scanMetadataValuesHead(::java::lang::Object* value)
{
    return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->valueHeadMap(value));
}

java::util::SortedMap* rice::persistence::MemoryStorage::scanMetadataValuesNull()
{
    return new ::rice::p2p::util::ImmutableSortedMap(npc(metadata)->valueNullMap());
}

int64_t rice::persistence::MemoryStorage::getTotalSize()
{
    return currentSize;
}

int32_t rice::persistence::MemoryStorage::getSize()
{
    return npc(idSet)->numElements();
}

int32_t rice::persistence::MemoryStorage::getSize(::java::lang::Object* obj)
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        ::java::io::ObjectOutputStream* oos = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(baos)));
        npc(oos)->writeObject(obj);
        npc(oos)->close();
        return npc(npc(baos)->toByteArray_())->length;
    } catch (::java::io::IOException* e) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(obj))
            ->append(u" was not serialized correctly! "_j)
            ->append(npc(e)->toString())->toString(), e);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::MemoryStorage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.MemoryStorage", 30);
    return c;
}

java::lang::Class* rice::persistence::MemoryStorage::getClass0()
{
    return class_();
}

