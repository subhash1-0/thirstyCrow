// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1.hpp>

#include <java/util/Map.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>

rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1(InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3 *InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this(InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this)
    , nodeId(nodeId)
    , proxyAddress(proxyAddress)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1::run()
{
    InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_this->InternetPastryNodeFactory_this->newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), true);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1::getClass0()
{
    return class_();
}

