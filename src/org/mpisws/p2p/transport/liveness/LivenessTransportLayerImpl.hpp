// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/OverrideLiveness.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual LivenessTypes
    , public virtual LivenessTransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual OverrideLiveness
{

public:
    typedef ::java::lang::Object super;
    int32_t PING_DELAY {  };
    float PING_JITTER {  };
    int32_t NUM_PING_TRIES {  };
    int64_t BACKOFF_INITIAL {  };
    int32_t BACKOFF_LIMIT {  };
    int64_t CHECK_DEAD_THROTTLE {  };
    int32_t DEFAULT_RTO {  };

public: /* package */
    int32_t RTO_UBOUND {  };
    int32_t RTO_LBOUND {  };
    double gainH {  };
    double gainG {  };

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::time::TimeSource* time {  };
    ::rice::selector::Timer* timer {  };
    ::java::util::Random* random {  };

public:
    static constexpr int8_t HDR_NORMAL { int8_t(0) };
    static constexpr int8_t HDR_PING { int8_t(1) };
    static constexpr int8_t HDR_PONG { int8_t(2) };

public: /* package */
    ::java::util::Map* managers {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle);

public:
    void clearState(::java::lang::Object* i) override;
    bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::P2PSocket* getLSocket(::org::mpisws::p2p::transport::P2PSocket* s, LivenessTransportLayerImpl_EntityManager* manager);
    virtual LivenessTransportLayerImpl_EntityManager* getManager(::java::lang::Object* i);
    virtual LivenessTransportLayerImpl_EntityManager* deleteManager(::java::lang::Object* i);
    int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;

public: /* package */
    bool connectionExceptionMeansFaulty_ {  };

public:
    virtual void connectionExceptionMeansFaulty(bool b);
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual bool cancelLivenessCheck(::java::lang::Object* i, ::java::util::Map* options);
    virtual bool cancelLivenessCheck(LivenessTransportLayerImpl_EntityManager* manager, ::java::util::Map* options);
    ::java::lang::String* toString() override;
    bool ping(::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void pong(::java::lang::Object* i, int64_t senderTime, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;

public: /* package */
    bool destroyed {  };

public:
    void destroy() override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

public: /* package */
    ::java::util::List* livenessListeners {  };

public:
    void addLivenessListener(LivenessListener* name) override;
    bool removeLivenessListener(LivenessListener* name) override;

private:
    void notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options);

public: /* package */
    ::java::util::List* pingListeners {  };

public:
    void addPingListener(PingListener* name) override;
    bool removePingListener(PingListener* name) override;

private:
    void notifyPingListenersPing(::java::lang::Object* i);
    void notifyPingListenersPong(::java::lang::Object* i, int32_t rtt, ::java::util::Map* options);

public:
    void setLiveness(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options) override;

    // Generated
    LivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle);
protected:
    LivenessTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_ping_3;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
