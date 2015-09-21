// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2(MultiInetAddressTransportLayerImpl_openSocket_1 *MultiInetAddressTransportLayerImpl_openSocket_1_this, ::java::nio::ByteBuffer* b, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, MultiInetSocketAddress* i)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiInetAddressTransportLayerImpl_openSocket_1_this(MultiInetAddressTransportLayerImpl_openSocket_1_this)
    , b(b)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
    , i(i)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead || !canWrite)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to write! "_j)->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    if(npc(socket)->write(b) < 0) {
        npc(deliverSocketToMe)->receiveException(handle, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Remote node closed socket while opening.  Try again."_j));
        return;
    }
    if(npc(b)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(deliverSocketToMe)->receiveResult(handle, new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(i, socket, MultiInetAddressTransportLayerImpl_openSocket_1_this->MultiInetAddressTransportLayerImpl_this->logger, MultiInetAddressTransportLayerImpl_openSocket_1_this->MultiInetAddressTransportLayerImpl_this->errorHandler, npc(socket)->getOptions()));
    }
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(deliverSocketToMe)->receiveException(handle, e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2::getClass0()
{
    return class_();
}

