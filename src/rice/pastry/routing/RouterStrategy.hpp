// Generated from /pastry-2.1/src/rice/pastry/routing/RouterStrategy.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::routing::RouterStrategy
    : public virtual ::java::lang::Object
{
    virtual ::rice::pastry::NodeHandle* pickNextHop(RouteMessage* msg, ::java::util::Iterator* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
