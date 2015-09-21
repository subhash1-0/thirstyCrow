// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/NodeChangeStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::identity::NodeChangeStrategy
    : public virtual ::java::lang::Object
{
    virtual bool canChange(::java::lang::Object* oldDest, ::java::lang::Object* newDest) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
