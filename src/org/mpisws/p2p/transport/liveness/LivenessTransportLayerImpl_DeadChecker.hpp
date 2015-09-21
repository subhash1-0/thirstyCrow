// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* protected */
    int32_t tries {  };
    int32_t numTries {  };
    LivenessTransportLayerImpl_EntityManager* manager {  };

public: /* package */
    int64_t startTime {  };
    int32_t initialDelay {  };
    ::java::util::Map* options {  };
protected:
    void ctor(LivenessTransportLayerImpl_EntityManager* manager, int32_t numTries, int32_t initialDelay, ::java::util::Map* options);

public:
    virtual void pingResponse(int64_t RTT, ::java::util::Map* options);
    void run() override;
    bool cancel() override;
    ::java::lang::String* toString() override;

    // Generated
    LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, int32_t numTries, int32_t initialDelay, ::java::util::Map* options);
protected:
    LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    LivenessTransportLayerImpl *LivenessTransportLayerImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl;
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_ping_3;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
