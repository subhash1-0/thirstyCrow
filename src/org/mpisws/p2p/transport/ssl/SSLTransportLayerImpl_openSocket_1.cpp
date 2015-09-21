// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayer.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1::SSLTransportLayerImpl_openSocket_1(SSLTransportLayerImpl *SSLTransportLayerImpl_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLTransportLayerImpl_this(SSLTransportLayerImpl_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(s, ex);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    SSLTransportLayerImpl_this->getSocketManager(SSLTransportLayerImpl_this, sock, new SSLTransportLayerImpl_openSocket_1_receiveResult_1_1(this, deliverSocketToMe, ret), false, SSLTransportLayerImpl_this->clientAuth != SSLTransportLayer::CLIENT_AUTH_NONE);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1::getClass0()
{
    return class_();
}

