// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache_cache_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/Storage.hpp>

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
rice::persistence::LRUCache_cache_2::LRUCache_cache_2(LRUCache *LRUCache_this, ::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCache_this(LRUCache_this)
    , id(id)
    , metadata(metadata)
    , obj(obj)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::LRUCache_cache_2::receiveResult(::java::lang::Object* o)
{
    {
        synchronized synchronized_0(LRUCache_this->order);
        {
            npc(LRUCache_this->order)->addFirst(static_cast< ::java::lang::Object* >(id));
        }
    }
    npc(LRUCache_this->storage)->store(id, metadata, obj, c);
}

void rice::persistence::LRUCache_cache_2::receiveException(::java::lang::Exception* e)
{
    npc(c)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache_cache_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::LRUCache_cache_2::getClass0()
{
    return class_();
}

