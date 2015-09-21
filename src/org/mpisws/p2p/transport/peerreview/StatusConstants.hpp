// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/StatusConstants.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::StatusConstants
    : public virtual ::java::lang::Object
{
    static constexpr int32_t STATUS_TRUSTED { int32_t(0) };
    static constexpr int32_t STATUS_SUSPECTED { int32_t(1) };
    static constexpr int32_t STATUS_EXPOSED { int32_t(2) };

    // Generated
    static ::java::lang::Class *class_();
};
