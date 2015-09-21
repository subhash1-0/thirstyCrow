// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpoint_routeHelper_1
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
    PastryEndpoint_routeHelper_1(PastryEndpoint *PastryEndpoint_this, ::rice::p2p::commonapi::Id* final_key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    PastryEndpoint *PastryEndpoint_this;
    ::rice::p2p::commonapi::Id* final_key;
    PastryEndpointMessage* pm;
    ::rice::p2p::commonapi::NodeHandle* hint;
    ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryEndpoint;
    friend class PastryEndpoint_PEDeserializer;
    friend class PastryEndpoint_routeHelper_2;
    friend class PastryEndpoint_networkNeighbors_3;
};
