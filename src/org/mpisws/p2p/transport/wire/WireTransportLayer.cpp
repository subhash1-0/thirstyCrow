// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/WireTransportLayer.java
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>

#include <java/lang/String.hpp>

java::lang::String*& org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE()
{
    clinit();
    return OPTION_TRANSPORT_TYPE_;
}
java::lang::String* org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE_;

constexpr int32_t org::mpisws::p2p::transport::wire::WireTransportLayer::TRANSPORT_TYPE_DATAGRAM;

constexpr int32_t org::mpisws::p2p::transport::wire::WireTransportLayer::TRANSPORT_TYPE_GUARANTEED;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::WireTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.WireTransportLayer", 48);
    return c;
}

