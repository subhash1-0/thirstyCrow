// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t seq {  };
    ::rice::p2p::util::SortedLinkedList* queue {  };
    ::java::util::Collection* sockets {  };
    ::java::lang::ref::WeakReference* identifier {  };
    ::org::mpisws::p2p::transport::SocketRequestHandle* pendingSocket {  };
    ::org::mpisws::p2p::transport::P2PSocket* writingSocket {  };
    ::org::mpisws::p2p::transport::P2PSocket* closeWritingSocket {  };
    PriorityTransportLayerImpl_EntityManager_MessageWrapper* messageThatIsBeingWritten {  };

private:
    bool registered {  };
protected:
    void ctor(::java::lang::Object* identifier);

public:
    ::java::lang::String* toString() override;
    virtual void clearState();
    virtual bool closeMe(::org::mpisws::p2p::transport::P2PSocket* socket);
    virtual void primarySocketAvailable(::org::mpisws::p2p::transport::P2PSocket* s, ::org::mpisws::p2p::transport::SocketRequestHandle* receipt);
    virtual void setWritingSocket(::org::mpisws::p2p::transport::P2PSocket* s);

public: /* protected */
    virtual void scheduleToWriteIfNeeded();

public:
    virtual void openPrimarySocketHelper(::java::lang::Object* i, ::java::util::Map* options);

public: /* package */
    ::rice::selector::TimerTask* livenessChecker {  };

public:
    virtual void startLivenessChecker(::java::lang::Object* temp, ::java::util::Map* options);
    virtual void stopLivenessChecker();

private:
    PriorityTransportLayerImpl_EntityManager_MessageWrapper* peek();
    PriorityTransportLayerImpl_EntityManager_MessageWrapper* poll();
    bool haveMessageToSend();

public:
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    virtual void receiveSocketException(::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::java::lang::Exception* ex);

private:
    void enqueue(PriorityTransportLayerImpl_EntityManager_MessageWrapper* ret);

public:
    virtual void markDead();
    virtual void purge(::java::io::IOException* ioe);

public: /* package */
    ::java::util::Map* pendingBigMessages {  };

public: /* protected */
    virtual void handleBigMsgSocket(::org::mpisws::p2p::transport::P2PSocket* socket);

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* send(::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

public: /* protected */
    virtual bool complete(PriorityTransportLayerImpl_EntityManager_MessageWrapper* wrapper);

public:
    virtual void clearAndEnqueue(PriorityTransportLayerImpl_EntityManager_MessageWrapper* wrapper);
    virtual int32_t queueLength();
    virtual int64_t bytesPending();
    virtual ::java::util::List* getPendingMessages();

    // Generated

public: /* package */
    PriorityTransportLayerImpl_EntityManager(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, ::java::lang::Object* identifier);
protected:
    PriorityTransportLayerImpl_EntityManager(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    PriorityTransportLayerImpl *PriorityTransportLayerImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class PriorityTransportLayerImpl;
    friend class PriorityTransportLayerImpl_incomingSocket_1;
    friend class PriorityTransportLayerImpl_openSocket_2;
    friend class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_1;
    friend class PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2;
    friend class PriorityTransportLayerImpl_sendMessage_3;
    friend class PriorityTransportLayerImpl_destroy_4;
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
