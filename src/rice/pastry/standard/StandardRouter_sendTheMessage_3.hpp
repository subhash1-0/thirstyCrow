// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter_sendTheMessage_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason) override;

    // Generated
    StandardRouter_sendTheMessage_3(StandardRouter *StandardRouter_this, ::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle);
    static ::java::lang::Class *class_();
    StandardRouter *StandardRouter_this;
    ::rice::pastry::routing::RouteMessage* rm;
    ::rice::pastry::NodeHandle* handle;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter;
    friend class StandardRouter_AliveRouterStrategy;
    friend class StandardRouter_StandardRouter_1;
    friend class StandardRouter_route_2;
    friend class StandardRouter_getBestRoutingCandidates_4;
};
