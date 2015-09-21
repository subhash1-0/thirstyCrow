// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <javax/net/ssl/KeyManagerFactory.hpp>
#include <javax/net/ssl/SSLContext.hpp>
#include <javax/net/ssl/TrustManager.hpp>
#include <javax/net/ssl/TrustManagerFactory.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLSocketManager.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace net
    {
        namespace ssl
        {
typedef ::SubArray< ::javax::net::ssl::TrustManager, ::java::lang::ObjectArray > TrustManagerArray;
        } // ssl
    } // net
} // javax

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

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::SSLTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::SSLTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, ::rice::environment::Environment* env)  /* throws(IOException) */
    : SSLTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,keyStore,trustStore,env);
}

org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::SSLTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, int32_t clientAuth, ::rice::environment::Environment* env)  /* throws(IOException) */
    : SSLTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,keyStore,trustStore,clientAuth,env);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(tl, keyStore, trustStore, CLIENT_AUTH_REQUIRED, env);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, int32_t clientAuth, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    if(clientAuth != CLIENT_AUTH_NONE && clientAuth != CLIENT_AUTH_REQUIRED)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"clientAuth type:"_j)->append(clientAuth)
            ->append(u" not supported."_j)->toString());

    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(SSLTransportLayerImpl::class_(), nullptr);
    this->tl = tl;
    errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger, ::rice::environment::logging::Logger::WARNING);
    this->clientAuth = clientAuth;
    try {
        this->context = ::javax::net::ssl::SSLContext::getInstance(u"TLS"_j);
        auto passphrase = npc(u""_j)->toCharArray_();
        auto kmf = ::javax::net::ssl::KeyManagerFactory::getInstance(u"SunX509"_j);
        npc(kmf)->init_(keyStore, passphrase);
        auto tmf = ::javax::net::ssl::TrustManagerFactory::getInstance(u"SunX509"_j);
        npc(tmf)->init_(trustStore);
        auto tms = npc(tmf)->getTrustManagers();
        if(clientAuth == CLIENT_AUTH_NONE)
            tms = nullptr;

        npc(context)->init_(npc(kmf)->getKeyManagers(), tms, nullptr);
        npc(tl)->setCallback(this);
    } catch (::java::lang::RuntimeException* re) {
        throw re;
    } catch (::java::lang::Exception* nsae) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(nsae));
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new SSLTransportLayerImpl_openSocket_1(this, deliverSocketToMe, ret), options));
    return ret;
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    getSocketManager(this, s, new SSLTransportLayerImpl_incomingSocket_2(this, s), true, clientAuth != CLIENT_AUTH_NONE);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::destroy()
{
    npc(tl)->destroy();
}

java::lang::Object* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

org::mpisws::p2p::transport::ssl::SSLSocketManager* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::getSocketManager(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth)
{
    return new SSLSocketManager(sslTL, s, c, server, useClientAuth);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.ssl.SSLTransportLayerImpl", 50);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl::getClass0()
{
    return class_();
}

