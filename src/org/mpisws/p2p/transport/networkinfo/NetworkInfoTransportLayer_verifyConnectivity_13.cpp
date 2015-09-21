// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_13.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13::NetworkInfoTransportLayer_verifyConnectivity_13(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ConnectivityResult* deliverResultToMe, ::java::net::InetSocketAddress* probeAddress, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , deliverResultToMe(deliverResultToMe)
    , probeAddress(probeAddress)
    , local(local)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(sock)->register_(true, false, new NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1(this, deliverResultToMe, probeAddress, local));
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverResultToMe)->receiveException(ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13::getClass0()
{
    return class_();
}

