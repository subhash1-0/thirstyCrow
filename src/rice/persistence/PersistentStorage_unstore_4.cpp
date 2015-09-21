// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_unstore_4.hpp>

#include <java/io/File.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashSet.hpp>
#include <rice/environment/logging/Logger.hpp>
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
rice::persistence::PersistentStorage_unstore_4::PersistentStorage_unstore_4(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , id(id)
{
    clinit();
    ctor(c, sm);
}

rice::persistence::PersistentStorage_unstore_4::PersistentStorage_unstore_4(PersistentStorage *PersistentStorage_this, ::rice::p2p::commonapi::Id* id)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
    , id(id)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_unstore_4::toString()
{
    return ::java::lang::StringBuilder().append(u"unstore "_j)->append(static_cast< ::java::lang::Object* >(id))->toString();
}

java::lang::Object* rice::persistence::PersistentStorage_unstore_4::doWork() /* throws(Exception) */
{
    {
        synchronized synchronized_0(PersistentStorage_this->statLock);
        {
            PersistentStorage_this->numDeletes++;
        }
    }
    auto objFile = PersistentStorage_this->getFile(id);
    if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: Unstoring data under "_j)->append(npc(id)->toStringFull())
            ->append(u" of size "_j)
            ->append(npc(objFile)->length())
            ->append(u" in "_j)
            ->append(PersistentStorage_this->name)->toString());

    if(PersistentStorage_this->index) {
        {
            synchronized synchronized_1(PersistentStorage_this->metadata);
            {
                npc(PersistentStorage_this->metadata)->remove(id);
                npc(PersistentStorage_this->dirty)->add(static_cast< ::java::lang::Object* >(npc(objFile)->getParentFile()));
            }
        }
    }
    if((objFile == nullptr) || (!npc(objFile)->exists()))
        return ::java::lang::Boolean::FALSE();

    PersistentStorage_this->decreaseUsedSpace(npc(objFile)->length());
    PersistentStorage::deleteFile(objFile);
    return ::java::lang::Boolean::TRUE();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_unstore_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_unstore_4::getClass0()
{
    return class_();
}

