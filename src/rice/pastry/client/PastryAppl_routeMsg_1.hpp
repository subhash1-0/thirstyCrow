// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::client::PastryAppl_routeMsg_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::MessageReceipt
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;
    ::rice::pastry::messaging::Message* getMessage() override;
    ::rice::pastry::Id* getId() override;
    ::rice::pastry::NodeHandle* getHint() override;

    // Generated
    PastryAppl_routeMsg_1(PastryAppl *PastryAppl_this, ::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    PastryAppl *PastryAppl_this;
    ::rice::pastry::Id* key;
    ::rice::pastry::messaging::Message* msg;
    ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryAppl;
    friend class PastryAppl_LeafSetObserver;
    friend class PastryAppl_RouteSetObserver;
    friend class PastryAppl_routeMsg_2;
};
