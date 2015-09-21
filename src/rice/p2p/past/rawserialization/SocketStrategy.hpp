// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/SocketStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::past::rawserialization::SocketStrategy
    : public virtual ::java::lang::Object
{
    static constexpr int32_t TYPE_INSERT { int32_t(1) };
    static constexpr int32_t TYPE_FETCH { int32_t(2) };
    virtual bool sendAlongSocket(int32_t sendType, ::rice::p2p::past::PastContent* content) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
