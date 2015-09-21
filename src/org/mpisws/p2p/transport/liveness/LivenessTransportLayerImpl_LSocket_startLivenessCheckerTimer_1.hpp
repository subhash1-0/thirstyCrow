// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1(LivenessTransportLayerImpl_LSocket *LivenessTransportLayerImpl_LSocket_this);
    static ::java::lang::Class *class_();
    LivenessTransportLayerImpl_LSocket *LivenessTransportLayerImpl_LSocket_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl;
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_ping_3;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket;
};
