// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager_checkLiveness_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    LivenessTransportLayerImpl_EntityManager_checkLiveness_1(LivenessTransportLayerImpl_EntityManager *LivenessTransportLayerImpl_EntityManager_this, int32_t theRTO, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    LivenessTransportLayerImpl_EntityManager *LivenessTransportLayerImpl_EntityManager_this;
    int32_t theRTO;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl;
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_ping_3;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_LSocket;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
