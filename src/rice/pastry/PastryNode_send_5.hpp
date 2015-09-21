// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::PastryNode_send_5
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageReceipt
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;
    NodeHandle* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    ::rice::pastry::messaging::Message* getMessage() override;
    ::java::lang::String* toString() override;

    // Generated
    PastryNode_send_5(PastryNode *PastryNode_this, ::java::util::Map* options, ::rice::pastry::messaging::Message* msg);
    static ::java::lang::Class *class_();
    PastryNode *PastryNode_this;
    ::java::util::Map* options;
    ::rice::pastry::messaging::Message* msg;

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
    friend class PastryNode_send_6;
    friend class PastryNode_send_7;
};
