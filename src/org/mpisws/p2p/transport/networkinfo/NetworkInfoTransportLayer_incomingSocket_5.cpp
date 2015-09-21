// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_incomingSocket_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <rice/environment/logging/Logger.hpp>
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

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::NetworkInfoTransportLayer_incomingSocket_5(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* s)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , s(s)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::init()
{
    bb = ::java::nio::ByteBuffer::allocate(npc(NetworkInfoTransportLayer::HEADER_PASSTHROUGH())->length);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(bb);
    if(npc(NetworkInfoTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(NetworkInfoTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u"): bytesRead = "_j)
            ->append(bytesRead)
            ->append(u" remaining:"_j)
            ->append(npc(bb)->remaining())->toString());

    if(bytesRead < 0) {
        npc(socket)->close();
        return;
    }
    if(npc(bb)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    auto ret = npc(bb)->array();
    if(npc(ret)->length > 1)
        throw new ::java::lang::RuntimeException(u"Make this work over the array, implementation expectes header to be 1 byte."_j);

    if(npc(NetworkInfoTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(NetworkInfoTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u"): type = "_j)
            ->append((*ret)[int32_t(0)])->toString());

    switch ((*ret)[int32_t(0)]) {
    case NetworkInfoTransportLayer::HEADER_PASSTHROUGH_BYTE:
        npc(NetworkInfoTransportLayer_this->callback)->incomingSocket(socket);
        return;
    case NetworkInfoTransportLayer::HEADER_IP_ADDRESS_REQUEST_BYTE:
        NetworkInfoTransportLayer_this->handleIpRequest(socket);
        return;
    case NetworkInfoTransportLayer::HEADER_NODES_REQUEST_BYTE:
        NetworkInfoTransportLayer_this->handleNodesRequest(socket);
        return;
    case NetworkInfoTransportLayer::HEADER_PROBE_REQUEST_BYTE:
        NetworkInfoTransportLayer_this->handleProbeRequest(socket);
        return;
    case NetworkInfoTransportLayer::HEADER_PROBE_RESPONSE_BYTE:
        NetworkInfoTransportLayer_this->handleProbeResponse(socket);
        return;
    case NetworkInfoTransportLayer::HEADER_ID_REQUEST_BYTE:
        NetworkInfoTransportLayer_this->handleIdRequest(socket);
        return;
    default:
        npc(NetworkInfoTransportLayer_this->errorHandler)->receivedUnexpectedData(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), ret, 0, npc(socket)->getOptions());
    }

}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(NetworkInfoTransportLayer_this->errorHandler)->receivedException(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier()), ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_incomingSocket_5::getClass0()
{
    return class_();
}

