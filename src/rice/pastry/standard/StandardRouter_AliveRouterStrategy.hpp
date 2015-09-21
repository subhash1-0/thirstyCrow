// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouterStrategy.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter_AliveRouterStrategy
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouterStrategy
{

public:
    typedef ::java::lang::Object super;
    ::rice::pastry::NodeHandle* pickNextHop(::rice::pastry::routing::RouteMessage* msg, ::java::util::Iterator* i) override;

    // Generated
    StandardRouter_AliveRouterStrategy();
protected:
    StandardRouter_AliveRouterStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter;
    friend class StandardRouter_StandardRouter_1;
    friend class StandardRouter_route_2;
    friend class StandardRouter_sendTheMessage_3;
    friend class StandardRouter_getBestRoutingCandidates_4;
};
