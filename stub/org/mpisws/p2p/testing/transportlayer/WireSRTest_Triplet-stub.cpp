// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/WireSRTest.java
#include <org/mpisws/p2p/testing/transportlayer/WireSRTest_Triplet.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::WireSRTest_Triplet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::WireSRTest_Triplet(::org::mpisws::p2p::transport::sourceroute::SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b)
    : WireSRTest_Triplet(*static_cast< ::default_init_tag* >(0))
{
    ctor(path, a, b);
}


void ::org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::ctor(::org::mpisws::p2p::transport::sourceroute::SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::ctor(::org::mpisws::p2p::transport::sourceroute::SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.WireSRTest.Triplet", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireSRTest_Triplet::getClass0()
{
    return class_();
}

