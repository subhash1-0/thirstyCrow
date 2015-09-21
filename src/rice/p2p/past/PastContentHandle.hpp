// Generated from /pastry-2.1/src/rice/p2p/past/PastContentHandle.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::past::PastContentHandle
    : public virtual ::java::io::Serializable
{
    virtual ::rice::p2p::commonapi::Id* getId() = 0;
    virtual ::rice::p2p::commonapi::NodeHandle* getNodeHandle() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
