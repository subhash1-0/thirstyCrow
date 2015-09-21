// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Cancellable, ::java::lang::ObjectArray > CancellableArray;
        } // commonapi
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::boolArray* timeout, ::rice::p2p::commonapi::CancellableArray* cancelme, ::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , InternetPastryNodeFactory_this(InternetPastryNodeFactory_this)
    , timeout(timeout)
    , cancelme(cancelme)
    , nodeId(nodeId)
    , proxyAddress(proxyAddress)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3::run()
{
    (*timeout)[int32_t(0)] = true;
    npc((*cancelme)[int32_t(0)])->cancel();
    npc(npc(InternetPastryNodeFactory_this->environment)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1(this, nodeId, proxyAddress, deliverResultToMe)), static_cast< int64_t >(int32_t(1000)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3::getClass0()
{
    return class_();
}

