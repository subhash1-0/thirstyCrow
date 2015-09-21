// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter_route_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    StandardRouter_route_2(StandardRouter *StandardRouter_this, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    StandardRouter *StandardRouter_this;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter;
    friend class StandardRouter_AliveRouterStrategy;
    friend class StandardRouter_StandardRouter_1;
    friend class StandardRouter_sendTheMessage_3;
    friend class StandardRouter_getBestRoutingCandidates_4;
};
