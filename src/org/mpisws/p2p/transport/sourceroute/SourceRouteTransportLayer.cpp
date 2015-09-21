// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayer.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayer.hpp>

#include <java/lang/String.hpp>

java::lang::String*& org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer::OPTION_SOURCE_ROUTE()
{
    clinit();
    return OPTION_SOURCE_ROUTE_;
}
java::lang::String* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer::OPTION_SOURCE_ROUTE_;

constexpr int32_t org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer::DONT_SOURCE_ROUTE;

constexpr int32_t org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer::ALLOW_SOURCE_ROUTE;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.SourceRouteTransportLayer", 62);
    return c;
}

