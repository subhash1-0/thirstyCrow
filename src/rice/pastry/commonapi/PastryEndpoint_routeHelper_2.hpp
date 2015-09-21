// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouteMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpoint_routeHelper_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouteMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop) override;
    void sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e) override;

    // Generated
    PastryEndpoint_routeHelper_2(PastryEndpoint *PastryEndpoint_this, ::rice::p2p::commonapi::Id* final_key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::p2p::commonapi::MessageReceipt* ret);
    static ::java::lang::Class *class_();
    PastryEndpoint *PastryEndpoint_this;
    ::rice::p2p::commonapi::Id* final_key;
    PastryEndpointMessage* pm;
    ::rice::p2p::commonapi::NodeHandle* hint;
    ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe;
    ::rice::p2p::commonapi::MessageReceipt* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryEndpoint;
    friend class PastryEndpoint_PEDeserializer;
    friend class PastryEndpoint_routeHelper_1;
    friend class PastryEndpoint_networkNeighbors_3;
};
