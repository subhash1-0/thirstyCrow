// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_BufferReader
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* buf {  };
protected:
    void ctor(int32_t size, ::org::mpisws::p2p::transport::P2PSocket* socket);

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;
    virtual void done(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    ::java::lang::String* toString() override;

    // Generated
    PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, int32_t size, ::org::mpisws::p2p::transport::P2PSocket* socket);
protected:
    PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
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
    friend class PriorityTransportLayerImpl_EntityManager_MessageWrapper;
    friend class PriorityTransportLayerImpl_EntityManager_SizeReader;
};