// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getCommonAPITransportLayer_9.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <Array.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::SocketPastryNodeFactory_getCommonAPITransportLayer_9(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::rice::environment::Environment* environment)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , environment(environment)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::init()
{
    logger = npc(npc(environment)->getLogManager())->getLogger(SocketPastryNodeFactory::class_(), nullptr);
}

void rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::receivedUnexpectedData(TransportLayerNodeHandle* id, ::int8_tArray* bytes, int32_t location, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING) {
        auto s = u""_j;
        auto numBytes = int32_t(8);
        if(npc(bytes)->length < numBytes)
            numBytes = npc(bytes)->length;

        for (auto i = int32_t(0); i < numBytes; i++) {
            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append((*bytes)[i])->append(u","_j)->toString())->toString();
        }
        npc(logger)->log(::java::lang::StringBuilder().append(u"Unexpected data from "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" "_j)
            ->append(s)->toString());
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::receivedUnexpectedData(::java::lang::Object* i, ::int8_tArray* bytes, int32_t location, ::java::util::Map* options)
{ 
    receivedUnexpectedData(dynamic_cast< TransportLayerNodeHandle* >(i), bytes, location, options);
}

void rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::receivedException(TransportLayerNodeHandle* i, ::java::lang::Throwable* error)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
        if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(error) != nullptr) {
            auto nife = java_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(error);
            npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping message "_j)->append(static_cast< ::java::lang::Object* >(npc(nife)->getAttemptedMessage()))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(nife)->getIdentifier()))
                ->append(u" because it is faulty."_j)->toString());
            if(npc(i)->isAlive()) {
                auto nh = java_cast< TransportLayerNodeHandle* >(i);
                npc(logger)->logException(::java::lang::StringBuilder().append(u"NodeIsFaultyException thrown for non-dead node. "_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u" "_j)
                    ->append(npc(nh)->getLiveness())->toString(), nife);
            }
        }
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::receivedException(::java::lang::Object* i, ::java::lang::Throwable* error)
{ 
    receivedException(dynamic_cast< TransportLayerNodeHandle* >(i), error);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_9::getClass0()
{
    return class_();
}

