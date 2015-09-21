// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/CantVerifyConnectivityException.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>
#include <rice/selector/TimerTask.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::boolArray* timeout, ::rice::selector::TimerTask* timer, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , InternetPastryNodeFactory_this(InternetPastryNodeFactory_this)
    , timeout(timeout)
    , timer(timer)
    , nodeId(nodeId)
    , proxyAddress(proxyAddress)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::init()
{
    udpSuccess_ = false;
    tcpSuccess_ = false;
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    udpSuccess_ = true;
    complete();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    tcpSuccess_ = true;
    complete();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::complete()
{
    if(tcpSuccess_ && udpSuccess_ && !(*timeout)[int32_t(0)]) {
        npc(timer)->cancel();
        InternetPastryNodeFactory_this->newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), false);
    }
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::receiveException(::java::lang::Exception* e)
{
    npc(timer)->cancel();
    if(dynamic_cast< ::org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException* >(e) != nullptr) {
        if(InternetPastryNodeFactory_this->shouldFindExternalAddress(npc(npc(proxyAddress)->getInnermostAddress())->getAddress())) {
            InternetPastryNodeFactory_this->newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), true);
        } else {
            InternetPastryNodeFactory_this->newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), false);
        }
    } else {
        InternetPastryNodeFactory_this->newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), true);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4::getClass0()
{
    return class_();
}

