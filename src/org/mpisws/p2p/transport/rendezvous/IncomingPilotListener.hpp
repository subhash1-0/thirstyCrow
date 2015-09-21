// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/IncomingPilotListener.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::IncomingPilotListener
    : public virtual ::java::lang::Object
{
    virtual void pilotOpening(::java::lang::Object* i) = 0;
    virtual void pilotClosed(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
