// Generated from /pastry-2.1/src/rice/pastry/standard/ProximityNeighborSelector.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::standard::ProximityNeighborSelector
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Cancellable* getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
