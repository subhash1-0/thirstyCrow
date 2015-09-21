// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/SerializerListener.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::identity::SerializerListener
    : public virtual ::java::lang::Object
{
    virtual void nodeHandleFound(::java::lang::Object* handle) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
