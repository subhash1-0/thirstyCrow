// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java
#include <rice/pastry/standard/StandardJoinProtocol_handleIntermediateHop_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/standard/StandardJoinProtocol.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2::StandardJoinProtocol_handleIntermediateHop_2(StandardJoinProtocol *StandardJoinProtocol_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardJoinProtocol_this(StandardJoinProtocol_this)
{
    clinit();
    ctor();
}

void rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2::sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop)
{
    if(npc(StandardJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(StandardJoinProtocol_this->logger)->log(::java::lang::StringBuilder().append(u"sendSuccess("_j)->append(static_cast< ::java::lang::Object* >(message))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(nextHop))->toString());

}

void rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2::sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e)
{
    if(npc(StandardJoinProtocol_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(StandardJoinProtocol_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(message))
            ->append(u") "_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2::getClass0()
{
    return class_();
}

