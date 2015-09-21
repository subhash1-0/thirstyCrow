// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/DefaultForwardSourceRouteStrategy.java
#include <org/mpisws/p2p/transport/sourceroute/DefaultForwardSourceRouteStrategy.hpp>

org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy::DefaultForwardSourceRouteStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy::DefaultForwardSourceRouteStrategy()
    : DefaultForwardSourceRouteStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy::forward(::java::lang::Object* nextHop, SourceRoute* sr, bool socket, ::java::util::Map* options)
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.DefaultForwardSourceRouteStrategy", 70);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy::getClass0()
{
    return class_();
}

