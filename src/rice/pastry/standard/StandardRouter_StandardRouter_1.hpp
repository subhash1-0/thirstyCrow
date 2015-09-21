// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter_StandardRouter_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    StandardRouter_StandardRouter_1(StandardRouter *StandardRouter_this, ::rice::pastry::PastryNode* thePastryNode);
    static ::java::lang::Class *class_();
    StandardRouter *StandardRouter_this;
    ::rice::pastry::PastryNode* thePastryNode;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter;
    friend class StandardRouter_AliveRouterStrategy;
    friend class StandardRouter_route_2;
    friend class StandardRouter_sendTheMessage_3;
    friend class StandardRouter_getBestRoutingCandidates_4;
};
