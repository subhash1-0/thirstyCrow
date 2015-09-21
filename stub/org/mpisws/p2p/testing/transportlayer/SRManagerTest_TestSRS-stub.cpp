// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java
#include <org/mpisws/p2p/testing/transportlayer/SRManagerTest_TestSRS.hpp>

#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::SRManagerTest_TestSRS(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::SRManagerTest_TestSRS(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
    : SRManagerTest_TestSRS(*static_cast< ::default_init_tag* >(0))
{
    ctor(local);
}


void ::org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)");
}

java::util::Collection* org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::getSourceRoutes(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination)
{ /* stub */
    unimplemented_(u"java::util::Collection* org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::getSourceRoutes(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination)");
    return 0;
}

java::util::Collection* org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::getSourceRoutes(::java::lang::Object* destination)
{ 
    return getSourceRoutes(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(destination));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.SRManagerTest.TestSRS", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS::getClass0()
{
    return class_();
}

