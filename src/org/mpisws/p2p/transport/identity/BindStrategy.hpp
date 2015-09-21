// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/BindStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::identity::BindStrategy
    : public virtual ::java::lang::Object
{
    virtual bool accept(::java::lang::Object* u, ::java::lang::Object* l, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
