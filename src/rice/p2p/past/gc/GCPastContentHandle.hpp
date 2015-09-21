// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>

struct rice::p2p::past::gc::GCPastContentHandle
    : public virtual ::rice::p2p::past::PastContentHandle
{
    virtual int64_t getVersion() = 0;
    virtual int64_t getExpiration() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
