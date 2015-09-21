// Generated from /pastry-2.1/src/rice/p2p/aggregation/Aggregation.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::aggregation::Aggregation
    : public virtual ::java::lang::Object
{
    virtual ::java::io::Serializable* getHandle() = 0;
    virtual void setHandle(::java::io::Serializable* handle, ::rice::Continuation* command) = 0;
    virtual void flush(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;
    virtual void flush(::rice::Continuation* command) = 0;
    virtual void rollback(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;
    virtual void reset(::rice::Continuation* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
