// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/SanityChecker.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::identity::SanityChecker
    : public virtual ::java::lang::Object
{
    virtual bool isSane(::java::lang::Object* upper, ::java::lang::Object* middle) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
