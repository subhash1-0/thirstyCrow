// Generated from /pastry-2.1/src/rice/pastry/routing/Router.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::routing::Router
    : public virtual ::java::lang::Object
{
    virtual void route(RouteMessage* rm) = 0;
    virtual ::java::util::Iterator* getBestRoutingCandidates(::rice::pastry::Id* key) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
