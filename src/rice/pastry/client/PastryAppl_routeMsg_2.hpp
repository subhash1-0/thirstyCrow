// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouteMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::client::PastryAppl_routeMsg_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouteMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop) override;
    void sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e) override;

    // Generated
    PastryAppl_routeMsg_2(PastryAppl *PastryAppl_this, ::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::p2p::commonapi::MessageReceipt* ret);
    static ::java::lang::Class *class_();
    PastryAppl *PastryAppl_this;
    ::rice::pastry::Id* key;
    ::rice::pastry::messaging::Message* msg;
    ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe;
    ::rice::p2p::commonapi::MessageReceipt* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryAppl;
    friend class PastryAppl_LeafSetObserver;
    friend class PastryAppl_RouteSetObserver;
    friend class PastryAppl_routeMsg_1;
};
