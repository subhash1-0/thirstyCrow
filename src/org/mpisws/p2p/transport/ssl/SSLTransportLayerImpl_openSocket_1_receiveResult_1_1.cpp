// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1(SSLTransportLayerImpl_openSocket_1 *SSLTransportLayerImpl_openSocket_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLTransportLayerImpl_openSocket_1_this(SSLTransportLayerImpl_openSocket_1_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(deliverSocketToMe)->receiveException(ret, exception);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveResult(SSLSocketManager* result)
{
    npc(deliverSocketToMe)->receiveResult(ret, result);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< SSLSocketManager* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_openSocket_1_receiveResult_1_1::getClass0()
{
    return class_();
}

