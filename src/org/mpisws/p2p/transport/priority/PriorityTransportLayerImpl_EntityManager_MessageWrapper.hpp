// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <java/nio/ByteBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t priority {  };
    int32_t seq {  };
    ::java::lang::Object* myIdentifier {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
    ::java::nio::ByteBuffer* originalMessage {  };
    ::java::nio::ByteBuffer* message {  };
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe {  };
    ::java::util::Map* options {  };
    int32_t originalSize {  };
    bool cancelled {  };
    bool completed {  };
protected:
    void ctor(::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, int32_t priority, int32_t seq);

public:
    virtual MessageInfo* getMessageInfo();
    virtual void complete();
    virtual bool receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    virtual void drop();
    virtual int32_t compareTo(PriorityTransportLayerImpl_EntityManager_MessageWrapper* that);
    ::java::lang::Object* getIdentifier() override;
    ::java::nio::ByteBuffer* getMessage() override;
    ::java::util::Map* getOptions() override;
    virtual void reset();
    bool cancel() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    PriorityTransportLayerImpl_EntityManager_MessageWrapper(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, int32_t priority, int32_t seq);
protected:
    PriorityTransportLayerImpl_EntityManager_MessageWrapper(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int32_t compareTo(::java::lang::Object* o) override;
    PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PriorityTransportLayerImpl;
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
    friend class PriorityTransportLayerImpl_EntityManager_SizeReader;
    friend class PriorityTransportLayerImpl_EntityManager_BufferReader;
};
