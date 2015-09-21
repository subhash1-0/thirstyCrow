// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java
#include <rice/pastry/standard/StandardJoinProtocol_respondToJoiner_3.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/join/JoinRequest.hpp>
#include <rice/pastry/standard/StandardJoinProtocol.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3::StandardJoinProtocol_respondToJoiner_3(StandardJoinProtocol *StandardJoinProtocol_this, ::rice::pastry::join::JoinRequest* jr)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardJoinProtocol_this(StandardJoinProtocol_this)
    , jr(jr)
{
    clinit();
    ctor();
}

void rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
    if(npc(StandardJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(StandardJoinProtocol_this->logger)->log(::java::lang::StringBuilder().append(u"acceptJoin.sent("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(jr))->toString());

}

void rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason2)
{
    ::java::lang::Throwable* reason = reason2;
    if(npc(StandardJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG) {
        npc(StandardJoinProtocol_this->logger)->logException(::java::lang::StringBuilder().append(u"acceptJoin.sendFailed("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(jr))->toString(), reason);
        while (npc(reason)->getCause() != nullptr) {
            reason = npc(reason)->getCause();
            npc(StandardJoinProtocol_this->logger)->logException(u"because"_j, reason);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_respondToJoiner_3::getClass0()
{
    return class_();
}

