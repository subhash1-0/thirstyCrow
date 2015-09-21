// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/PilotManager.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::PilotManager
    : public virtual ::java::lang::Object
{
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openPilot(::java::lang::Object* i, ::rice::Continuation* deliverAckToMe) = 0;
    virtual void closePilot(::java::lang::Object* i) = 0;
    virtual void addOutgoingPilotListener(OutgoingPilotListener* listener) = 0;
    virtual void removeOutgoingPilotListener(OutgoingPilotListener* listener) = 0;
    virtual void addIncomingPilotListener(IncomingPilotListener* listener) = 0;
    virtual void removeIncomingPilotListener(IncomingPilotListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
