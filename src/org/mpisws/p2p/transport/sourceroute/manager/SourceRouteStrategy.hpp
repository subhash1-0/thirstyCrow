// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy
    : public virtual ::java::lang::Object
{
    virtual ::java::util::Collection* getSourceRoutes(::java::lang::Object* destination) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
