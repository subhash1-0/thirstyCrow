// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTypes.java
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>

constexpr int32_t org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE;

constexpr int32_t org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED;

constexpr int32_t org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD;

constexpr int32_t org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTypes::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.LivenessTypes", 47);
    return c;
}

