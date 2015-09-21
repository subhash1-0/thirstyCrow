// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;

public: /* package */
    LivenessTransportLayerImpl_EntityManager* manager {  };
    ::java::lang::Object* hardRef {  };
    ::rice::selector::TimerTask* livenessCheckerTimer {  };
    bool closed {  };
protected:
    void ctor(LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef);

public:
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    virtual void startLivenessCheckerTimer();
    virtual void stopLivenessCheckerTimer();
    void close() override;
    ::java::lang::String* toString() override;

    // Generated
    LivenessTransportLayerImpl_LSocket(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef);
protected:
    LivenessTransportLayerImpl_LSocket(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&);


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
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
