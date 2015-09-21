// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/CantVerifyConnectivityException.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_13.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1(NetworkInfoTransportLayer_verifyConnectivity_13 *NetworkInfoTransportLayer_verifyConnectivity_13_this, ConnectivityResult* deliverResultToMe, ::java::net::InetSocketAddress* probeAddress, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_verifyConnectivity_13_this(NetworkInfoTransportLayer_verifyConnectivity_13_this)
    , deliverResultToMe(deliverResultToMe)
    , probeAddress(probeAddress)
    , local(local)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::init()
{
    readMe = ::java::nio::ByteBuffer::allocate(1);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(readMe);
    if(bytesRead < 0) {
        npc(deliverResultToMe)->receiveException(new ::org::mpisws::p2p::transport::ClosedChannelException(u"Channel closed before reporting success/failure"_j));
        npc(socket)->close();
        return;
    }
    if(npc(readMe)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    npc(readMe)->flip();
    auto ret = npc(readMe)->get();
    if(ret == 1) {
    } else {
        npc(deliverResultToMe)->receiveException(new CantVerifyConnectivityException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(probeAddress))->append(u" can't verify our connectivity for address "_j)
            ->append(static_cast< ::java::lang::Object* >(local))->toString()));
        return;
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverResultToMe)->receiveException(ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1::getClass0()
{
    return class_();
}

