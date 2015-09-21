// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache.hpp>

#include <java/io/BufferedOutputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <rice/persistence/LRUCache_setMaximumSize_3.hpp>
#include <rice/persistence/LRUCache_resize_4.hpp>
#include <rice/persistence/LRUCache_flush_5.hpp>
#include <rice/persistence/LRUCache_rename_1.hpp>
#include <rice/persistence/LRUCache_cache_2.hpp>
#include <rice/persistence/Storage.hpp>
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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::persistence::LRUCache::LRUCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::LRUCache::LRUCache(Storage* storage, int32_t maximumSize, ::rice::environment::Environment* env) 
    : LRUCache(*static_cast< ::default_init_tag* >(0))
{
    ctor(storage,maximumSize,env);
}

void rice::persistence::LRUCache::ctor(Storage* storage, int32_t maximumSize, ::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    this->storage = storage;
    this->maximumSize = maximumSize;
    this->order = new ::java::util::LinkedList();
    auto i = npc(npc(storage)->scan())->getIterator();
    while (npc(i)->hasNext()) 
                npc(order)->addLast(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(i)->next())));

}

rice::persistence::Storage* rice::persistence::LRUCache::getStorage()
{
    return storage;
}

void rice::persistence::LRUCache::rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c)
{
    npc(storage)->rename(oldId, newId, new LRUCache_rename_1(this, oldId, newId, c));
}

void rice::persistence::LRUCache::cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
{
    auto const size = getSize(obj);
    if(exists(id)) {
        {
            synchronized synchronized_0(order);
            {
                npc(order)->remove(static_cast< ::java::lang::Object* >(id));
                npc(order)->addFirst(static_cast< ::java::lang::Object* >(id));
            }
        }
        npc(c)->receiveResult(new ::java::lang::Boolean(true));
        return;
    }
    if(size > maximumSize) {
        npc(c)->receiveResult(new ::java::lang::Boolean(false));
        return;
    }
    ::rice::Continuation* const store = new LRUCache_cache_2(this, id, metadata, obj, c);
    auto totalSize = npc(storage)->getTotalSize();
    if(maximumSize - size < totalSize)
        resize(maximumSize - size, store);
    else
        npc(store)->receiveResult(::java::lang::Boolean::TRUE());
}

void rice::persistence::LRUCache::uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    {
        synchronized synchronized_1(order);
        {
            npc(order)->remove(static_cast< ::java::lang::Object* >(id));
        }
    }
    npc(storage)->unstore(id, c);
}

bool rice::persistence::LRUCache::exists(::rice::p2p::commonapi::Id* id)
{
    return npc(storage)->exists(id);
}

void rice::persistence::LRUCache::getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    if(!exists(id)) {
        npc(c)->receiveResult(nullptr);
        return;
    }
    {
        synchronized synchronized_2(this);
        {
            npc(order)->remove(static_cast< ::java::lang::Object* >(id));
            npc(order)->addFirst(static_cast< ::java::lang::Object* >(id));
        }
    }
    npc(storage)->getObject(id, c);
}

java::io::Serializable* rice::persistence::LRUCache::getMetadata(::rice::p2p::commonapi::Id* id)
{
    return npc(storage)->getMetadata(id);
}

void rice::persistence::LRUCache::setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command)
{
    npc(storage)->setMetadata(id, metadata, command);
}

rice::p2p::commonapi::IdSet* rice::persistence::LRUCache::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(storage)->scan(range);
}

rice::p2p::commonapi::IdSet* rice::persistence::LRUCache::scan()
{
    return npc(storage)->scan();
}

java::util::SortedMap* rice::persistence::LRUCache::scanMetadata(::rice::p2p::commonapi::IdRange* range)
{
    return npc(storage)->scanMetadata(range);
}

java::util::SortedMap* rice::persistence::LRUCache::scanMetadata()
{
    return npc(storage)->scanMetadata();
}

java::util::SortedMap* rice::persistence::LRUCache::scanMetadataValuesHead(::java::lang::Object* value)
{
    return npc(storage)->scanMetadataValuesHead(value);
}

java::util::SortedMap* rice::persistence::LRUCache::scanMetadataValuesNull()
{
    return npc(storage)->scanMetadataValuesNull();
}

int64_t rice::persistence::LRUCache::getMaximumSize()
{
    return maximumSize;
}

int32_t rice::persistence::LRUCache::getSize()
{
    return npc(storage)->getSize();
}

int64_t rice::persistence::LRUCache::getTotalSize()
{
    return npc(storage)->getTotalSize();
}

void rice::persistence::LRUCache::setMaximumSize(int32_t size, ::rice::Continuation* c)
{
    ::rice::Continuation* local = new LRUCache_setMaximumSize_3(this, size, c);
    if(size < maximumSize) {
        resize(size, local);
    } else {
        npc(local)->receiveResult(new ::java::lang::Boolean(true));
    }
}

void rice::persistence::LRUCache::resize(int32_t size, ::rice::Continuation* c)
{
    ::rice::Continuation* const remove = new LRUCache_resize_4(this, size, c);
    npc(remove)->receiveResult(::java::lang::Boolean::TRUE());
}

int32_t rice::persistence::LRUCache::getSize(::java::lang::Object* obj)
{
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        ::java::io::ObjectOutputStream* oos = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(baos)));
        npc(oos)->writeObject(obj);
        npc(oos)->close();
        return npc(npc(baos)->toByteArray_())->length;
    } catch (::java::io::IOException* e) {
        auto logger = npc(npc(environment)->getLogManager())->getLogger(LRUCache::class_(), nullptr);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u""_j, e);

        return ::java::lang::Integer::MAX_VALUE;
    }
}

void rice::persistence::LRUCache::flush(::rice::Continuation* c)
{
    npc(storage)->flush(new LRUCache_flush_5(this, c));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.LRUCache", 25);
    return c;
}

java::lang::Class* rice::persistence::LRUCache::getClass0()
{
    return class_();
}

