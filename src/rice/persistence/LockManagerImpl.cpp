// Generated from /pastry-2.1/src/rice/persistence/LockManagerImpl.java
#include <rice/persistence/LockManagerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>

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
rice::persistence::LockManagerImpl::LockManagerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::LockManagerImpl::LockManagerImpl(::rice::environment::Environment* env) 
    : LockManagerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::persistence::LockManagerImpl::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    this->locks = new ::java::util::HashMap();
    this->logger = npc(npc(env)->getLogManager())->getLogger(StorageManagerImpl::class_(), nullptr);
}

void rice::persistence::LockManagerImpl::lock(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c)
{
    ::rice::Continuation* torun = nullptr;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"locking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" for continuation "_j)
            ->append(static_cast< ::java::lang::Object* >(c))->toString());

    {
        synchronized synchronized_0(this);
        {
            if(npc(locks)->containsKey(static_cast< ::java::lang::Object* >(id))) {
                auto locklist = (java_cast< ::java::util::List* >(java_cast< ::java::lang::Object* >(npc(locks)->get(static_cast< ::java::lang::Object* >(id)))));
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"locking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u"; blocked on "_j)
                        ->append(npc(locklist)->size())
                        ->append(u" earlier continuations"_j)->toString());

                if(npc(locklist)->size() > 10 && npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"locking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u"; "_j)
                        ->append(npc(locklist)->size())
                        ->append(u" continuations in queue.  That seems large"_j)->toString());

                npc(locklist)->add(static_cast< ::java::lang::Object* >(c));
            } else {
                npc(locks)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(new ::java::util::LinkedList()));
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"locking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u"; no contention so running "_j)
                        ->append(static_cast< ::java::lang::Object* >(c))->toString());

                torun = c;
            }
        }
    }
    if(torun != nullptr)
        npc(torun)->receiveResult(nullptr);

}

void rice::persistence::LockManagerImpl::unlock(::rice::p2p::commonapi::Id* id)
{
    ::rice::Continuation* torun = nullptr;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"unlocking on id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

    {
        synchronized synchronized_1(this);
        {
            if(npc(locks)->containsKey(static_cast< ::java::lang::Object* >(id))) {
                if(npc((java_cast< ::java::util::List* >(java_cast< ::java::lang::Object* >(npc(locks)->get(static_cast< ::java::lang::Object* >(id))))))->isEmpty()) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"unlocking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                            ->append(u"; last out the door -- removing lock "_j)->toString());

                    npc(locks)->remove(static_cast< ::java::lang::Object* >(id));
                } else {
                    auto next = java_cast< ::rice::Continuation* >(java_cast< ::java::lang::Object* >(npc((java_cast< ::java::util::List* >(java_cast< ::java::lang::Object* >(npc(locks)->get(static_cast< ::java::lang::Object* >(id))))))->remove(int32_t(0))));
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"unlocking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                            ->append(u"; starting next continuation "_j)
                            ->append(static_cast< ::java::lang::Object* >(next))->toString());

                    torun = next;
                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"unlocking on id "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u"; no lock currently held!!"_j)->toString());

            }
        }
    }
    if(torun != nullptr)
        npc(torun)->receiveResult(nullptr);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::LockManagerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.LockManagerImpl", 32);
    return c;
}

java::lang::Class* rice::persistence::LockManagerImpl::getClass0()
{
    return class_();
}

