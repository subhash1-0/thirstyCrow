// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_send_7
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    PastryNode_send_7(PastryNode *PastryNode_this, ::rice::pastry::transport::PMessageReceiptImpl* ret, NodeHandle* handle, ::rice::pastry::messaging::PRawMessage* rm, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    PastryNode *PastryNode_this;
    ::rice::pastry::transport::PMessageReceiptImpl* ret;
    NodeHandle* handle;
    ::rice::pastry::messaging::PRawMessage* rm;
    ::org::mpisws::p2p::transport::MessageCallback* callback;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryNode;
    friend class PastryNode_getDefaultReadyStrategy_1;
    friend class PastryNode_destroy_2;
    friend class PastryNode_connect_3;
    friend class PastryNode_connect_3_run_3_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1;
    friend class PastryNode_connect_3_run_3_1_receiveResult_3_1_1_receiveSelectResult_3_1_1_1;
    friend class PastryNode_incomingSocket_4;
    friend class PastryNode_incomingSocket_4_receiveSelectResult_4_1;
    friend class PastryNode_send_5;
    friend class PastryNode_send_6;
};
