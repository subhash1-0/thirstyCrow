// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java
#include <rice/pastry/standard/ConsistentJoinProtocol_ConsistentJoinProtocol_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_FailedTime.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol.hpp>

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
rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1::ConsistentJoinProtocol_ConsistentJoinProtocol_1(ConsistentJoinProtocol *ConsistentJoinProtocol_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConsistentJoinProtocol_this(ConsistentJoinProtocol_this)
{
    clinit();
    ctor();
}

void rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1::run()
{
    if(npc(ConsistentJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(ConsistentJoinProtocol_this->logger)->log(u"CJP: Cleanup task."_j);

    {
        synchronized synchronized_0(ConsistentJoinProtocol_this->failed);
        {
            auto now = npc(npc(npc(ConsistentJoinProtocol_this->thePastryNode)->getEnvironment())->getTimeSource())->currentTimeMillis();
            auto expiration = now - ConsistentJoinProtocol_this->failedNodeExpirationTime;
            auto i = npc(npc(ConsistentJoinProtocol_this->failed)->values())->iterator();
            while (npc(i)->hasNext()) {
                auto ft = java_cast< ConsistentJoinProtocol_FailedTime* >(java_cast< ConsistentJoinProtocol_FailedTime* >(npc(i)->next()));
                if(npc(ft)->time < expiration) {
                    if(npc(ConsistentJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(ConsistentJoinProtocol_this->logger)->log(::java::lang::StringBuilder().append(u"CJP: Removing "_j)->append(static_cast< ::java::lang::Object* >(npc(ft)->handle))
                            ->append(u" from failed set."_j)->toString());

                    npc(i)->remove();
                    npc(npc(ft)->handle)->deleteObserver(static_cast< ::java::util::Observer* >(ConsistentJoinProtocol_this));
                    npc(ConsistentJoinProtocol_this->observing)->remove(static_cast< ::java::lang::Object* >(npc(ft)->handle));
                } else {
                    if(npc(ConsistentJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(ConsistentJoinProtocol_this->logger)->log(::java::lang::StringBuilder().append(u"CJP: Not Removing "_j)->append(static_cast< ::java::lang::Object* >(npc(ft)->handle))
                            ->append(u" from failed set until "_j)
                            ->append((npc(ft)->time + ConsistentJoinProtocol_this->failedNodeExpirationTime))
                            ->append(u" which is another "_j)
                            ->append((npc(ft)->time + ConsistentJoinProtocol_this->failedNodeExpirationTime - now))
                            ->append(u" millis."_j)->toString());

                }
            }
        }
    }
}

java::lang::String* rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1::toString()
{
    return ::java::lang::StringBuilder().append(u"CJP$cleanupTask{"_j)->append(static_cast< ::java::lang::Object* >(ConsistentJoinProtocol_this->thePastryNode))
        ->append(u"}"_j)
        ->append(cancelled)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1::getClass0()
{
    return class_();
}

