// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual PriorityTransportLayer
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* proximityProvider {  };

public:
    static constexpr int8_t PASSTHROUGH_SOCKET_B { int8_t(0) };
    static constexpr int8_t PRIMARY_SOCKET_B { int8_t(1) };
    static constexpr int8_t BIG_MSG_SOCKET_B { int8_t(2) };

private:
    static ::int8_tArray* PASSTHROUGH_SOCKET_;
    static ::int8_tArray* PRIMARY_SOCKET_;
    static ::int8_tArray* BIG_MSG_SOCKET_;

public:
    int32_t MAX_MSG_SIZE {  };
    int32_t MAX_QUEUE_SIZE {  };
    int32_t MAX_BIG_MSG_SIZE {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* protected */
    ::java::util::Map* entityManagers {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };

public: /* protected */
    ::rice::selector::SelectorManager* selectorManager {  };
    ::rice::environment::Environment* environment {  };
    ::java::util::ArrayList* primarySocketListeners {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proximityProvider, ::rice::environment::Environment* env, int32_t maxMsgSize, int32_t maxQueueSize, ::org::mpisws::p2p::transport::ErrorHandler* handler);

public:
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;

public: /* protected */
    bool destroyed {  };

public:
    void destroy() override;

public: /* protected */
    virtual PriorityTransportLayerImpl_EntityManager* getEntityManager(::java::lang::Object* i);
    virtual PriorityTransportLayerImpl_EntityManager* deleteEntityManager(::java::lang::Object* i);

public:
    void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;
    virtual void cancelLivenessChecker(::java::lang::Object* i);
    virtual void printMemStats(int32_t logLevel);

public: /* package */
    ::java::util::ArrayList* listeners {  };
    ::java::util::ArrayList* plisteners {  };

public:
    void addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) override;
    void removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener) override;
    void addPriorityTransportLayerListener(PriorityTransportLayerListener* listener) override;
    void removePriorityTransportLayerListener(PriorityTransportLayerListener* listener) override;
    virtual void notifyListenersRead(int32_t size, ::java::lang::Object* source, ::java::util::Map* options);
    virtual void notifyListenersWrote(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options);
    virtual void notifyListenersEnqueued(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options);
    virtual void notifyListenersDropped(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options);
    int64_t bytesPending(::java::lang::Object* i) override;
    int32_t queueLength(::java::lang::Object* i) override;
    ::java::util::List* getPendingMessages(::java::lang::Object* i) override;
    ::java::util::Collection* nodesWithPendingMessages() override;
    ::java::util::Map* connectionOptions(::java::lang::Object* i) override;
    int32_t connectionStatus(::java::lang::Object* i) override;
    void openPrimaryConnection(::java::lang::Object* i, ::java::util::Map* options) override;
    void addPrimarySocketListener(PrimarySocketListener* listener) override;
    void removePrimarySocketListener(PrimarySocketListener* listener) override;

    // Generated
    PriorityTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proximityProvider, ::rice::environment::Environment* env, int32_t maxMsgSize, int32_t maxQueueSize, ::org::mpisws::p2p::transport::ErrorHandler* handler);
protected:
    PriorityTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    static ::int8_tArray*& PASSTHROUGH_SOCKET();
    static ::int8_tArray*& PRIMARY_SOCKET();
    static ::int8_tArray*& BIG_MSG_SOCKET();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PriorityTransportLayerImpl_incomingSocket_1;
    friend class PriorityTransportLayerImpl_openSocket_2;
    friend class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_1;
    friend class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2;
    friend class PriorityTransportLayerImpl_sendMessage_3;
    friend class PriorityTransportLayerImpl_destroy_4;
    friend class PriorityTransportLayerImpl_EntityManager;
    friend class PriorityTransportLayerImpl_EntityManager_clearState_1;
    friend class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_2;
    friend class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3;
    friend class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_1;
    friend class PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2;
    friend class PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4;
    friend class PriorityTransportLayerImpl_EntityManager_PendingMessages;
    friend class PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage;
    friend class PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5;
    friend class PriorityTransportLayerImpl_EntityManager_send_6;
    friend class PriorityTransportLayerImpl_EntityManager_MessageWrapper;
    friend class PriorityTransportLayerImpl_EntityManager_SizeReader;
    friend class PriorityTransportLayerImpl_EntityManager_BufferReader;
};
