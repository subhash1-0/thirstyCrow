// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::DirectTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    bool acceptMessages_ {  };
    bool acceptSockets_ {  };
    ::java::lang::Object* localIdentifier {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    GenericNetworkSimulator* simulator {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::lang::Object* local, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::direct::NodeRecord* nr, ::rice::environment::Environment* env);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    virtual bool canReceiveSocket();
    virtual void finishReceiveSocket(::org::mpisws::p2p::transport::P2PSocket* acceptorEndpoint);
    virtual ::rice::environment::logging::Logger* getLogger();

public: /* package */
    int32_t seq {  };

public:
    virtual int32_t getNextSeq();
    virtual void incomingMessage(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual ::rice::environment::Environment* getEnvironment();
    virtual void clearState(::java::lang::Object* i);

    // Generated
    DirectTransportLayer(::java::lang::Object* local, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::direct::NodeRecord* nr, ::rice::environment::Environment* env);
protected:
    DirectTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class DirectTransportLayer_CancelAndClose;
};
