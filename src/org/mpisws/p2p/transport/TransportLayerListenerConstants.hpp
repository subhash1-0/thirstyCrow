// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/TransportLayerListenerConstants.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::TransportLayerListenerConstants
    : public virtual ::java::lang::Object
{
    static constexpr int32_t UNKNOWN { int32_t(-1) };
    static constexpr int32_t UDP { int32_t(0) };
    static constexpr int32_t TCP { int32_t(1) };
    static constexpr int32_t ENCRYPTED { int32_t(2) };
    static constexpr int32_t AUTHENTICATED { int32_t(4) };
    static constexpr int32_t OVERHEAD { int32_t(0) };
    static constexpr int32_t PASSTHROUGH { int32_t(1) };

    // Generated
    static ::java::lang::Class *class_();
};
