// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter_go_1.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1(ReplicationManagerImpl_ReplicationManagerDeleter_go_1 *ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{
    if(npc(::java::lang::Boolean::TRUE())->equals(result)) {
        if(npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Telling client to delete id "_j)->append(static_cast< ::java::lang::Object* >(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->id))->toString());

        if(npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"RMImpl.go "_j)->append(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->instance)
                ->append(u": removing id "_j)
                ->append(static_cast< ::java::lang::Object* >(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->id))->toString());

        npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->client)->remove(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->id, parent);
    } else {
        if(npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->ReplicationManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Object to remove "_j)->append(static_cast< ::java::lang::Object* >(ReplicationManagerImpl_ReplicationManagerDeleter_go_1_this->ReplicationManagerImpl_ReplicationManagerDeleter_this->id))
                ->append(u" Could not be reinserted.  Ignoring remove."_j)->toString());

        receiveResult(static_cast< ::java::lang::Object* >(::java::lang::Boolean::FALSE()));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1::getClass0()
{
    return class_();
}

