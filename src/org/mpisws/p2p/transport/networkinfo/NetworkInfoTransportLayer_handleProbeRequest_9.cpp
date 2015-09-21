// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ProbeStrategy.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::NetworkInfoTransportLayer_handleProbeRequest_9(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , socket(socket)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::init()
{
    sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto addr = ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(sib);
        auto uid = npc(sib)->readLong();
        npc(NetworkInfoTransportLayer_this->probeStrategy)->requestProbe(addr, uid, new NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1(this, socket));
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9::getClass0()
{
    return class_();
}

