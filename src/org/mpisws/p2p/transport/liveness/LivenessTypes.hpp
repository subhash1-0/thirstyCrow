// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTypes.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::liveness::LivenessTypes
    : public virtual ::java::lang::Object
{
    static constexpr int32_t LIVENESS_ALIVE { int32_t(1) };
    static constexpr int32_t LIVENESS_SUSPECTED { int32_t(2) };
    static constexpr int32_t LIVENESS_DEAD { int32_t(3) };
    static constexpr int32_t LIVENESS_DEAD_FOREVER { int32_t(4) };

    // Generated
    static ::java::lang::Class *class_();
};
