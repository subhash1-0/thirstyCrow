// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* temp, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this;
    ::java::lang::Object* temp;
    ::java::util::Map* options;

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
    friend class PriorityTransportLayerImpl_EntityManager_PendingMessages;
    friend class PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage;
    friend class PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5;
    friend class PriorityTransportLayerImpl_EntityManager_send_6;
    friend class PriorityTransportLayerImpl_EntityManager_MessageWrapper;
    friend class PriorityTransportLayerImpl_EntityManager_SizeReader;
    friend class PriorityTransportLayerImpl_EntityManager_BufferReader;
};
