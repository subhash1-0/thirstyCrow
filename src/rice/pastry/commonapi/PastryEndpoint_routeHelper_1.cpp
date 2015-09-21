// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java
#include <rice/pastry/commonapi/PastryEndpoint_routeHelper_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::commonapi::PastryEndpoint_routeHelper_1::PastryEndpoint_routeHelper_1(PastryEndpoint *PastryEndpoint_this, ::rice::p2p::commonapi::Id* final_key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryEndpoint_this(PastryEndpoint_this)
    , final_key(final_key)
    , pm(pm)
    , hint(hint)
    , deliverAckToMe(deliverAckToMe)
    , rm(rm)
{
    clinit();
    ctor();
}

bool rice::pastry::commonapi::PastryEndpoint_routeHelper_1::cancel()
{
    if(npc(PastryEndpoint_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryEndpoint_this->logger)->log(::java::lang::StringBuilder().append(u"routeHelper("_j)->append(static_cast< ::java::lang::Object* >(final_key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(pm))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(hint))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").cancel()"_j)->toString());

    return npc(rm)->cancel();
}

rice::p2p::commonapi::Message* rice::pastry::commonapi::PastryEndpoint_routeHelper_1::getMessage()
{
    return npc(pm)->getMessage();
}

rice::p2p::commonapi::Id* rice::pastry::commonapi::PastryEndpoint_routeHelper_1::getId()
{
    return final_key;
}

rice::p2p::commonapi::NodeHandle* rice::pastry::commonapi::PastryEndpoint_routeHelper_1::getHint()
{
    return hint;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_routeHelper_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_routeHelper_1::getClass0()
{
    return class_();
}

