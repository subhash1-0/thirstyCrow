// Generated from /pastry-2.1/src/rice/p2p/replication/Replication.java

#pragma once

#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::replication::Replication
    : public virtual ::java::lang::Object
{
    virtual void replicate() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
