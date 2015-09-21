// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/ssl/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual SSLTransportLayer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
    ::javax::net::ssl::SSLContext* context {  };

public: /* package */
    ::java::security::KeyPair* keyPair {  };

private:
    int32_t clientAuth {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, ::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, int32_t clientAuth, ::rice::environment::Environment* env) /* throws(IOException) */;

public:
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    void destroy() override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;

public: /* protected */
    virtual SSLSocketManager* getSocketManager(SSLTransportLayerImpl* sslTL, ::org::mpisws::p2p::transport::P2PSocket* s, ::rice::Continuation* c, bool server, bool useClientAuth);

    // Generated

public:
    SSLTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, ::rice::environment::Environment* env);
    SSLTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::security::KeyStore* keyStore, ::java::security::KeyStore* trustStore, int32_t clientAuth, ::rice::environment::Environment* env);
protected:
    SSLTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SSLTransportLayerImpl_openSocket_1;
    friend class SSLTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class SSLTransportLayerImpl_incomingSocket_2;
};
