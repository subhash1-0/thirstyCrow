// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayer.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>

#include <java/lang/String.hpp>

java::lang::String*& org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY()
{
    clinit();
    return OPTION_PRIORITY_;
}
java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY_;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::MAX_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::HIGH_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::MEDIUM_HIGH_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::MEDIUM_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::MEDIUM_LOW_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::LOW_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::LOWEST_PRIORITY;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::DEFAULT_PRIORITY;

constexpr int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_NOT_CONNECTED;

constexpr int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_CONNECTING;

constexpr int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayer::STATUS_CONNECTED;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayer", 56);
    return c;
}

