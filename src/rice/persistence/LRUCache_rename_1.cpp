// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java
#include <rice/persistence/LRUCache_rename_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/LRUCache.hpp>

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
rice::persistence::LRUCache_rename_1::LRUCache_rename_1(LRUCache *LRUCache_this, ::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCache_this(LRUCache_this)
    , oldId(oldId)
    , newId(newId)
{
    clinit();
    ctor(continuation);
}

void rice::persistence::LRUCache_rename_1::receiveResult(::java::lang::Object* o)
{
    {
        synchronized synchronized_0(LRUCache_this->order);
        {
            npc(LRUCache_this->order)->remove(static_cast< ::java::lang::Object* >(oldId));
            npc(LRUCache_this->order)->addFirst(static_cast< ::java::lang::Object* >(newId));
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LRUCache_rename_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::LRUCache_rename_1::getClass0()
{
    return class_();
}

