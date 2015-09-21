// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/simple/NextHopStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy
    : public virtual ::java::lang::Object
{
    virtual ::java::util::Collection* getNextHops(::java::lang::Object* destination) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
