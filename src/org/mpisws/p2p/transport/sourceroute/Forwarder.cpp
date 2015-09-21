// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/Forwarder.java
#include <org/mpisws/p2p/transport/sourceroute/Forwarder.hpp>

#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/Forwarder_HalfPipe.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <rice/environment/logging/Logger.hpp>

org::mpisws::p2p::transport::sourceroute::Forwarder::Forwarder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::Forwarder::Forwarder(SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka, ::org::mpisws::p2p::transport::P2PSocket* sockb, ::rice::environment::logging::Logger* logger) 
    : Forwarder(*static_cast< ::default_init_tag* >(0))
{
    ctor(sr,socka,sockb,logger);
}

void org::mpisws::p2p::transport::sourceroute::Forwarder::ctor(SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka, ::org::mpisws::p2p::transport::P2PSocket* sockb, ::rice::environment::logging::Logger* logger)
{
    super::ctor();
    this->sr = sr;
    this->socka = socka;
    this->sockb = sockb;
    this->logger = logger;
    new Forwarder_HalfPipe(this, socka, sockb);
    new Forwarder_HalfPipe(this, sockb, socka);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::Forwarder::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.Forwarder", 46);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::Forwarder::getClass0()
{
    return class_();
}

