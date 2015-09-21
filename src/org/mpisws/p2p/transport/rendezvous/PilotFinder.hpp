// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/PilotFinder.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::PilotFinder
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::Object* findPilot(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
