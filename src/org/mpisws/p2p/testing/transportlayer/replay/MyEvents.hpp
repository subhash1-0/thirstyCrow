// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyEvents.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::testing::transportlayer::replay::MyEvents
    : public virtual ::java::lang::Object
{
    static constexpr int16_t EVT_BOOT { int16_t(1001) };
    static constexpr int16_t EVT_SUBSCRIBE { int16_t(1002) };
    static constexpr int16_t EVT_PUBLISH { int16_t(1003) };

    // Generated
    static ::java::lang::Class *class_();
};
