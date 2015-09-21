// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl
    : public LivenessTransportLayerImpl
{

public:
    typedef LivenessTransportLayerImpl super;
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle);

public:
    ::org::mpisws::p2p::transport::P2PSocket* getLSocket(::org::mpisws::p2p::transport::P2PSocket* s, LivenessTransportLayerImpl_EntityManager* manager) override;
    void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */ override;

    // Generated
    AggressiveLivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle);
protected:
    AggressiveLivenessTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AggressiveLivenessTransportLayerImpl_ALSocket;
};
