// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::past::PastPolicy
    : public virtual ::java::lang::Object
{
    virtual void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::persistence::Cache* backup, Past* past, ::rice::Continuation* command) = 0;
    virtual bool allowInsert(PastContent* content) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
