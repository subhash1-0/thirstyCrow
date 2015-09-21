// Generated from /pastry-2.1/src/rice/p2p/commonapi/Message.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::Message
    : public virtual ::java::io::Serializable
{
    static constexpr int32_t MAX_PRIORITY { int32_t(-15) };
    static constexpr int32_t HIGH_PRIORITY { int32_t(-10) };
    static constexpr int32_t MEDIUM_HIGH_PRIORITY { int32_t(-5) };
    static constexpr int32_t MEDIUM_PRIORITY { int32_t(0) };
    static constexpr int32_t MEDIUM_LOW_PRIORITY { int32_t(5) };
    static constexpr int32_t LOW_PRIORITY { int32_t(10) };
    static constexpr int32_t LOWEST_PRIORITY { int32_t(15) };
    static constexpr int32_t DEFAULT_PRIORITY { int32_t(0) };
    virtual int32_t getPriority() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
