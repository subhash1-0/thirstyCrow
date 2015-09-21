// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java
#include <rice/pastry/commonapi/PastryEndpoint_routeHelper_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::commonapi::PastryEndpoint_routeHelper_2::PastryEndpoint_routeHelper_2(PastryEndpoint *PastryEndpoint_this, ::rice::p2p::commonapi::Id* final_key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::p2p::commonapi::MessageReceipt* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryEndpoint_this(PastryEndpoint_this)
    , final_key(final_key)
    , pm(pm)
    , hint(hint)
    , deliverAckToMe(deliverAckToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::pastry::commonapi::PastryEndpoint_routeHelper_2::sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop)
{
    if(npc(PastryEndpoint_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryEndpoint_this->logger)->log(::java::lang::StringBuilder().append(u"routeHelper("_j)->append(static_cast< ::java::lang::Object* >(final_key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(pm))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(hint))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").sendSuccess():"_j)
            ->append(static_cast< ::java::lang::Object* >(nextHop))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sent(ret);

}

void rice::pastry::commonapi::PastryEndpoint_routeHelper_2::sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e)
{
    if(npc(PastryEndpoint_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryEndpoint_this->logger)->log(::java::lang::StringBuilder().append(u"routeHelper("_j)->append(static_cast< ::java::lang::Object* >(final_key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(pm))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(hint))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").sendFailed("_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_routeHelper_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_routeHelper_2::getClass0()
{
    return class_();
}

