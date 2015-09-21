// Generated from /pastry-2.1/src/rice/persistence/LockManager.java

#pragma once

#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::persistence::LockManager
    : public virtual ::java::lang::Object
{
    virtual void lock(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) = 0;
    virtual void unlock(::rice::p2p::commonapi::Id* id) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
