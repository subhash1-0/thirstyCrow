// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java
#include <rice/pastry/standard/RapidRerouter_RouterNotification.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/priority/QueueOverflowException.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/standard/RapidRerouter.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::RapidRerouter_RouterNotification::RapidRerouter_RouterNotification(RapidRerouter *RapidRerouter_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RapidRerouter_this(RapidRerouter_this)
{
    clinit();
}

rice::pastry::standard::RapidRerouter_RouterNotification::RapidRerouter_RouterNotification(RapidRerouter *RapidRerouter_this, ::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle) 
    : RapidRerouter_RouterNotification(RapidRerouter_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(rm,handle);
}

void rice::pastry::standard::RapidRerouter_RouterNotification::init()
{
    failed = false;
    sent_ = false;
    cancelled = false;
}

void rice::pastry::standard::RapidRerouter_RouterNotification::ctor(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle)
{
    super::ctor();
    init();
    this->rm = rm;
    this->dest = handle;
    if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RapidRerouter_this->logger)->log(::java::lang::StringBuilder().append(u"RN.ctor() "_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u" to:"_j)
            ->append(static_cast< ::java::lang::Object* >(dest))->toString());

}

void rice::pastry::standard::RapidRerouter_RouterNotification::setCancellable(::rice::pastry::transport::PMessageReceipt* receipt)
{
    if(receipt == nullptr)
        if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".setCancellable(null)"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));


    this->cancellable = receipt;
}

void rice::pastry::standard::RapidRerouter_RouterNotification::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason)
{
    failed = true;
    cancellable = nullptr;
    npc(rm)->setTLCancellable(nullptr);
    if(dynamic_cast< ::org::mpisws::p2p::transport::priority::QueueOverflowException* >(reason) != nullptr) {
        RapidRerouter_this->removeFromPending(this, dest);
        if(npc(rm)->sendFailed(reason)) {
            if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                    ->append(u")=>"_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))->toString(), reason);

        } else {
            if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::FINE) {
                npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                    ->append(u")=>"_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))->toString(), reason);
            } else {
                if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::INFO) {
                    if(npc(msg)->getIdentifier() == nullptr) {
                        npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                            ->append(u")=>"_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(reason))
                            ->append(u" identifier was null!!!"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
                    } else {
                        npc(RapidRerouter_this->logger)->log(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                            ->append(u")=>"_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))
                            ->append(u" "_j)
                            ->append(static_cast< ::java::lang::Object* >(reason))->toString());
                    }
                }
            }
        }
        return;
    }
    if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(reason) != nullptr) {
        if(npc(npc(msg)->getIdentifier())->isAlive()) {
            if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::WARNING) {
                npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"Threw NodeIsFaultyException, and node is alive.  Node:"_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))
                    ->append(u" Liveness:"_j)
                    ->append(npc(npc(msg)->getIdentifier())->getLiveness())->toString(), reason);
                npc(RapidRerouter_this->logger)->logException(u"RRTrace"_j, new ::java::lang::Exception(u"Stack Trace"_j));
            }
        }
    }
    if(RapidRerouter_this->removeFromPending(this, dest)) {
        if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"Send failed on message "_j)->append(static_cast< ::java::lang::Object* >(rm))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(dest))
                ->append(u" rerouting."_j)
                ->append(static_cast< ::java::lang::Object* >(msg))->toString(), reason);

        RapidRerouter_this->rerouteMe(rm, dest, reason);
    } else {
        if(npc(rm)->sendFailed(reason)) {
            if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                    ->append(u")=>"_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))->toString(), reason);

        } else {
            if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(RapidRerouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(npc(msg)->getMessage()))
                    ->append(u")=>"_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(msg)->getIdentifier()))->toString(), reason);

        }
    }
}

void rice::pastry::standard::RapidRerouter_RouterNotification::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
    if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RapidRerouter_this->logger)->log(::java::lang::StringBuilder().append(u"Send success "_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u" to:"_j)
            ->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(msg))->toString());

    sent_ = true;
    cancellable = nullptr;
    npc(rm)->setTLCancellable(nullptr);
    RapidRerouter_this->removeFromPending(this, dest);
    npc(rm)->sendSuccess(dest);
}

bool rice::pastry::standard::RapidRerouter_RouterNotification::cancel()
{
    if(npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(RapidRerouter_this->logger)->log(::java::lang::StringBuilder().append(u"cancelling "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

    if(cancellable == nullptr && npc(RapidRerouter_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(RapidRerouter_this->logger)->log(::java::lang::StringBuilder().append(u"cancellable = null c:"_j)->append(cancelled)
            ->append(u" s:"_j)
            ->append(sent_)
            ->append(u" f:"_j)
            ->append(failed)->toString());

    cancelled = true;
    if(cancellable != nullptr)
        return npc(cancellable)->cancel();

    return true;
}

java::lang::String* rice::pastry::standard::RapidRerouter_RouterNotification::toString()
{
    return ::java::lang::StringBuilder().append(u"RN{"_j)->append(static_cast< ::java::lang::Object* >(rm))
        ->append(u"->"_j)
        ->append(static_cast< ::java::lang::Object* >(dest))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::RapidRerouter_RouterNotification::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.RapidRerouter.RouterNotification", 53);
    return c;
}

java::lang::Class* rice::pastry::standard::RapidRerouter_RouterNotification::getClass0()
{
    return class_();
}

