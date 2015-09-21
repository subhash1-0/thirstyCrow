// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_incomingSocket_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_incomingSocket_2::MultiInetAddressTransportLayerImpl_incomingSocket_2(MultiInetAddressTransportLayerImpl *MultiInetAddressTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiInetAddressTransportLayerImpl_this(MultiInetAddressTransportLayerImpl_this)
    , sib(sib)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_incomingSocket_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(MultiInetAddressTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(MultiInetAddressTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u"):receiveSelectResult()"_j)->toString());

    if(canWrite || !canRead)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to read! "_j)->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    try {
        auto eisa = MultiInetSocketAddress::build(sib);
        if(npc(MultiInetAddressTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(MultiInetAddressTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Read "_j)->append(static_cast< ::java::lang::Object* >(eisa))->toString());

        npc(MultiInetAddressTransportLayerImpl_this->callback)->incomingSocket(new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(eisa, socket, MultiInetAddressTransportLayerImpl_this->logger, MultiInetAddressTransportLayerImpl_this->errorHandler, npc(socket)->getOptions()));
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    } catch (::java::io::IOException* e) {
        if(npc(MultiInetAddressTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(MultiInetAddressTransportLayerImpl_this->errorHandler)->receivedException(new MultiInetSocketAddress(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier())), e);

    }
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_incomingSocket_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(MultiInetAddressTransportLayerImpl_this->errorHandler)->receivedException(new MultiInetSocketAddress(java_cast< ::java::net::InetSocketAddress* >(npc(socket)->getIdentifier())), e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_incomingSocket_2::getClass0()
{
    return class_();
}

