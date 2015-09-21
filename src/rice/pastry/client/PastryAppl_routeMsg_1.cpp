// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java
#include <rice/pastry/client/PastryAppl_routeMsg_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::client::PastryAppl_routeMsg_1::PastryAppl_routeMsg_1(PastryAppl *PastryAppl_this, ::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryAppl_this(PastryAppl_this)
    , key(key)
    , msg(msg)
    , deliverAckToMe(deliverAckToMe)
    , rm(rm)
{
    clinit();
    ctor();
}

bool rice::pastry::client::PastryAppl_routeMsg_1::cancel()
{
    if(npc(PastryAppl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryAppl_this->logger)->log(::java::lang::StringBuilder().append(u"routeMsg("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").cancel()"_j)->toString());

    return npc(rm)->cancel();
}

rice::pastry::messaging::Message* rice::pastry::client::PastryAppl_routeMsg_1::getMessage()
{
    return msg;
}

rice::pastry::Id* rice::pastry::client::PastryAppl_routeMsg_1::getId()
{
    return key;
}

rice::pastry::NodeHandle* rice::pastry::client::PastryAppl_routeMsg_1::getHint()
{
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::PastryAppl_routeMsg_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::client::PastryAppl_routeMsg_1::getClass0()
{
    return class_();
}

