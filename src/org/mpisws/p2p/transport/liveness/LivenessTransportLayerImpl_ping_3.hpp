// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_ping_3
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;

    // Generated
    LivenessTransportLayerImpl_ping_3(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::java::lang::Object* i, int64_t now, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    LivenessTransportLayerImpl *LivenessTransportLayerImpl_this;
    ::java::lang::Object* i;
    int64_t now;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl;
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
