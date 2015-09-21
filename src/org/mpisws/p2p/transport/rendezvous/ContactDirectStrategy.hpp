// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy
    : public virtual ::java::lang::Object
{
    virtual bool canContactDirect(::java::lang::Object* remoteNode) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
