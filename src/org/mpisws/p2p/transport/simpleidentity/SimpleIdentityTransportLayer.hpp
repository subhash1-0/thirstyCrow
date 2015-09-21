// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::rice::environment::logging::Logger* logger {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };

public: /* protected */
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    Serializer* serializer {  };

public: /* package */
    LocalIdentifierStrategy* localIdStrategy {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, Serializer* serializer, LocalIdentifierStrategy* localIdStrategy, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler) /* throws(IOException) */;

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ override;

    // Generated
    SimpleIdentityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, Serializer* serializer, LocalIdentifierStrategy* localIdStrategy, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler);
protected:
    SimpleIdentityTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy;
    friend class SimpleIdentityTransportLayer_openSocket_1;
    friend class SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1;
    friend class SimpleIdentityTransportLayer_incomingSocket_2;
};
