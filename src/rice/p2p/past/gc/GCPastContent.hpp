// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/PastContent.hpp>

struct rice::p2p::past::gc::GCPastContent
    : public virtual ::rice::p2p::past::PastContent
{
    virtual int64_t getVersion() = 0;
    virtual GCPastContentHandle* getHandle(GCPast* local, int64_t expiration) = 0;
    virtual GCPastMetadata* getMetadata(int64_t expiration) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) = 0;
};
