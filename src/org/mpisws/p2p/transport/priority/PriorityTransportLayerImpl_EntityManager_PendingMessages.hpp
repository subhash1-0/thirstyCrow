// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* i {  };
    ::java::util::LinkedList* msgs {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
    ::java::nio::ByteBuffer* header {  };
protected:
    void ctor(::java::lang::Object* i);

public:
    virtual void start(::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* addMessage(::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    virtual void receiveException(::java::lang::Exception* ex);
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;

public: /* protected */
    virtual void sendNextMessage() /* throws(IOException) */;

    // Generated

public:
    PriorityTransportLayerImpl_EntityManager_PendingMessages(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* i);
protected:
    PriorityTransportLayerImpl_EntityManager_PendingMessages(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this;
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
    friend class PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage;
    friend class PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5;
    friend class PriorityTransportLayerImpl_EntityManager_send_6;
    friend class PriorityTransportLayerImpl_EntityManager_MessageWrapper;
    friend class PriorityTransportLayerImpl_EntityManager_SizeReader;
    friend class PriorityTransportLayerImpl_EntityManager_BufferReader;
};
