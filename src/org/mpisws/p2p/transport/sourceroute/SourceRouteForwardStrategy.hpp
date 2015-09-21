// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::sourceroute::SourceRouteForwardStrategy
    : public virtual ::java::lang::Object
{
    virtual bool forward(::java::lang::Object* nextHop, SourceRoute* sr, bool socket, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
