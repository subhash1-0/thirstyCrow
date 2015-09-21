// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getOptionsAdder_10.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_getOptionsAdder_10::SocketPastryNodeFactory_getOptionsAdder_10(SocketPastryNodeFactory *SocketPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
{
    clinit();
    ctor();
}

java::util::Map* rice::pastry::socket::SocketPastryNodeFactory_getOptionsAdder_10::addOptions(::java::util::Map* options, ::rice::p2p::commonapi::rawserialization::RawMessage* m1)
{
    ::rice::p2p::commonapi::Message* m = m1;
    if(dynamic_cast< ::rice::pastry::routing::RouteMessage* >(m) != nullptr) {
        auto rm = java_cast< ::rice::pastry::routing::RouteMessage* >(m);
        m = npc(rm)->internalMsg;
        if(m == nullptr)
            m = rm;

    }
    if(dynamic_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(m) != nullptr) {
        auto pem = java_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(m);
        m = npc(pem)->getMessage();
        options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR(), ::java::lang::Integer::valueOf(npc(pem)->getDestination()));
    }
    if(dynamic_cast< ::rice::pastry::messaging::Message* >(m) != nullptr) {
        auto pm = java_cast< ::rice::pastry::messaging::Message* >(m);
        options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR(), ::java::lang::Integer::valueOf(npc(pm)->getDestination()));
    }
    if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m) != nullptr) {
        auto rm = java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m);
        options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE(), ::java::lang::Short::valueOf(npc(rm)->getType()));
    }
    return ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING(), npc(m)->toString(), ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS(), npc(npc(m)->getClass())->getName());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getOptionsAdder_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getOptionsAdder_10::getClass0()
{
    return class_();
}

