// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PrimarySocketListener.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::priority::PrimarySocketListener
    : public virtual ::java::lang::Object
{
    virtual void notifyPrimarySocketOpened(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual void notifyPrimarySocketClosed(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
