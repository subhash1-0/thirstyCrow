// Generated from /pastry-2.1/src/rice/pastry/NodeHandleFetcher.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeHandleFetcher
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Cancellable* getNodeHandle(::java::lang::Object* o, ::rice::Continuation* c) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
