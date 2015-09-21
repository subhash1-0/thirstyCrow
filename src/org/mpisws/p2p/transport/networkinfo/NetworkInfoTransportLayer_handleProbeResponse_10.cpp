// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeResponse_10.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>

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

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::NetworkInfoTransportLayer_handleProbeResponse_10(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , socket(socket)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::init()
{
    sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto uid = npc(sib)->readLong();
        npc(java_cast< ConnectivityResult* >(npc(NetworkInfoTransportLayer_this->verifyConnectionRequests)->get(::java::lang::Long::valueOf(uid))))->tcpSuccess(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), npc(socket)->getOptions());
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeResponse_10::getClass0()
{
    return class_();
}

