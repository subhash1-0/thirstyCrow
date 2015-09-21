// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/SocketCountListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::SocketCountListener
    : public virtual ::java::lang::Object
{
    virtual void socketOpened(::java::lang::Object* i, ::java::util::Map* options, bool outgoing) = 0;
    virtual void socketClosed(::java::lang::Object* i, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
