// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java
#include <rice/p2p/replication/manager/ReplicationManagerImpl_informClient_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerHelper.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>

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

rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1::ReplicationManagerImpl_informClient_1(ReplicationManagerImpl *ReplicationManagerImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::CancellableTask* timer)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerImpl_this(ReplicationManagerImpl_this)
    , id(id)
    , timer(timer)
{
    clinit();
    ctor();
}

void rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1::receiveResult(::java::lang::Object* o)
{
    if(!(new ::java::lang::Boolean(true))->equals(o)) {
        if(dynamic_cast< ::java::lang::Throwable* >(o) != nullptr) {
            if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(ReplicationManagerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Fetching of id "_j)->append(static_cast< ::java::lang::Object* >(id))
                    ->append(u" failed with "_j)->toString(), java_cast< ::java::lang::Throwable* >(o));

        } else {
            if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fetching of id "_j)->append(static_cast< ::java::lang::Object* >(id))
                    ->append(u" failed with "_j)
                    ->append(static_cast< ::java::lang::Object* >(o))->toString());

        }
    }
    if(npc(ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Successfully fetched id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

    npc(timer)->cancel();
    npc(ReplicationManagerImpl_this->helper)->message(id);
}

void rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1::receiveException(::java::lang::Exception* e)
{
    receiveResult(static_cast< ::java::lang::Object* >(e));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_informClient_1::getClass0()
{
    return class_();
}

