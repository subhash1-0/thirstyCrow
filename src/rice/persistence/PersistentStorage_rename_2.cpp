// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_rename_2.hpp>

#include <java/io/File.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/util/ReverseTreeMap.hpp>
#include <rice/persistence/PersistentStorage.hpp>

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
rice::persistence::PersistentStorage_rename_2::PersistentStorage_rename_2(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , oldId(oldId)
    , newId(newId)
{
    clinit();
    ctor(c, sm);
}

rice::persistence::PersistentStorage_rename_2::PersistentStorage_rename_2(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , oldId(oldId)
    , newId(newId)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_rename_2::toString()
{
    return ::java::lang::StringBuilder().append(u"rename "_j)->append(static_cast< ::java::lang::Object* >(oldId))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(newId))->toString();
}

java::lang::Object* rice::persistence::PersistentStorage_rename_2::doWork() /* throws(Exception) */
{
    {
        synchronized synchronized_0(PersistentStorage_this->statLock);
        {
            PersistentStorage_this->numRenames++;
        }
    }
    auto f = PersistentStorage_this->getFile(oldId);
    if((f != nullptr) && (npc(f)->exists())) {
        auto g = PersistentStorage_this->getFile(newId);
        PersistentStorage::renameFile(f, g);
        PersistentStorage_this->checkDirectory(npc(g)->getParentFile());
        if(PersistentStorage_this->index) {
            {
                synchronized synchronized_1(PersistentStorage_this->metadata);
                {
                    npc(PersistentStorage_this->metadata)->put(newId, npc(PersistentStorage_this->metadata)->get(oldId));
                    npc(PersistentStorage_this->metadata)->remove(oldId);
                }
            }
        }
        return ::java::lang::Boolean::TRUE();
    } else {
        return ::java::lang::Boolean::FALSE();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_rename_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_rename_2::getClass0()
{
    return class_();
}

