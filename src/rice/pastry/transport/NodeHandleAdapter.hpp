// Generated from /pastry-2.1/src/rice/pastry/transport/NodeHandleAdapter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <rice/pastry/NodeHandle.hpp>

struct default_init_tag;

class rice::pastry::transport::NodeHandleAdapter
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider {  };
    ::rice::pastry::boot::Bootstrapper* boot {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::rice::pastry::NodeHandle* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::rice::pastry::NodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::rice::pastry::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    virtual bool checkLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options);
    virtual int32_t getLiveness(::rice::pastry::NodeHandle* i, ::java::util::Map* options);
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    virtual int32_t proximity(::rice::pastry::NodeHandle* i, ::java::util::Map* options);
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener) override;
    virtual ::org::mpisws::p2p::transport::TransportLayer* getTL();
    virtual void clearState(::rice::pastry::NodeHandle* i);

    // Generated
    NodeHandleAdapter(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider);
protected:
    NodeHandleAdapter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void clearState(::java::lang::Object* i) override;
    virtual int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
};
