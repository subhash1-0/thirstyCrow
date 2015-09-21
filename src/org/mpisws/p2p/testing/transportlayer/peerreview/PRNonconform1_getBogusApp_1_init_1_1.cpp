// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1_getBogusApp_1_init_1_1.hpp>

#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1_getBogusApp_1.hpp>

org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1_init_1_1::PRNonconform1_getBogusApp_1_init_1_1(PRNonconform1_getBogusApp_1 *PRNonconform1_getBogusApp_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRNonconform1_getBogusApp_1_this(PRNonconform1_getBogusApp_1_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1_init_1_1::run()
{
    PRNonconform1_getBogusApp_1_this->sendMessage();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1_init_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1_init_1_1::getClass0()
{
    return class_();
}

