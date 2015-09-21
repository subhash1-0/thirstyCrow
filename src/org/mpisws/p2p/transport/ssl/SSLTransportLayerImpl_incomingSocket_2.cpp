// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_incomingSocket_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>

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

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::SSLTransportLayerImpl_incomingSocket_2(SSLTransportLayerImpl *SSLTransportLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* s)
    : super(*static_cast< ::default_init_tag* >(0))
    , SSLTransportLayerImpl_this(SSLTransportLayerImpl_this)
    , s(s)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::receiveException(::java::lang::Exception* exception)
{
    npc(SSLTransportLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), exception);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::receiveResult(SSLSocketManager* result)
{
    try {
        npc(SSLTransportLayerImpl_this->callback)->incomingSocket(result);
    } catch (::java::io::IOException* ioe) {
        npc(result)->close();
        npc(SSLTransportLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), ioe);
    }
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< SSLSocketManager* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl_incomingSocket_2::getClass0()
{
    return class_();
}

