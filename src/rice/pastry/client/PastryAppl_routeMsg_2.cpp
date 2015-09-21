// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java
#include <rice/pastry/client/PastryAppl_routeMsg_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/messaging/Message.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::client::PastryAppl_routeMsg_2::PastryAppl_routeMsg_2(PastryAppl *PastryAppl_this, ::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::p2p::commonapi::MessageReceipt* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryAppl_this(PastryAppl_this)
    , key(key)
    , msg(msg)
    , deliverAckToMe(deliverAckToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void rice::pastry::client::PastryAppl_routeMsg_2::sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop)
{
    if(npc(PastryAppl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryAppl_this->logger)->log(::java::lang::StringBuilder().append(u"routeMsg("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").sendSuccess():"_j)
            ->append(static_cast< ::java::lang::Object* >(nextHop))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sent(ret);

}

void rice::pastry::client::PastryAppl_routeMsg_2::sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e)
{
    if(npc(PastryAppl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastryAppl_this->logger)->log(::java::lang::StringBuilder().append(u"routeMsg("_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u").sendFailed("_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(ret, e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::PastryAppl_routeMsg_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::client::PastryAppl_routeMsg_2::getClass0()
{
    return class_();
}

