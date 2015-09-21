// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringNode_route_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::MessageReceipt
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;
    ::rice::p2p::commonapi::Message* getMessage() override;
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getHint() override;

    // Generated
    MultiringNode_route_2(MultiringNode *MultiringNode_this, ::rice::p2p::commonapi::rawserialization::RawMessage* message, RingId* id);
    static ::java::lang::Class *class_();
    MultiringNode *MultiringNode_this;
    ::rice::p2p::commonapi::rawserialization::RawMessage* message;
    RingId* id;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringNode;
    friend class MultiringNode_MultiringNode_1;
};
