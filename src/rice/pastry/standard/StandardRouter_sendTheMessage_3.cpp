// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter_sendTheMessage_3.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardRouter_sendTheMessage_3::StandardRouter_sendTheMessage_3(StandardRouter *StandardRouter_this, ::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardRouter_this(StandardRouter_this)
    , rm(rm)
    , handle(handle)
{
    clinit();
    ctor();
}

void rice::pastry::standard::StandardRouter_sendTheMessage_3::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
    npc(rm)->sendSuccess(handle);
}

void rice::pastry::standard::StandardRouter_sendTheMessage_3::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason)
{
    if(npc(rm)->sendFailed(reason)) {
        if(npc(StandardRouter_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
            npc(StandardRouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(rm))
                ->append(u")=>"_j)
                ->append(static_cast< ::java::lang::Object* >(handle))->toString(), reason);

    } else {
        if(npc(StandardRouter_this->logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(StandardRouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(rm))
                ->append(u")=>"_j)
                ->append(static_cast< ::java::lang::Object* >(handle))->toString(), reason);
        } else {
            if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(reason) != nullptr) {
                if(npc(StandardRouter_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(StandardRouter_this->logger)->log(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(rm))
                        ->append(u")=>"_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u" "_j)
                        ->append(static_cast< ::java::lang::Object* >(reason))->toString());

            } else {
                if(npc(StandardRouter_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(StandardRouter_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(rm))
                        ->append(u")=>"_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))->toString(), reason);

            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter_sendTheMessage_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter_sendTheMessage_3::getClass0()
{
    return class_();
}

