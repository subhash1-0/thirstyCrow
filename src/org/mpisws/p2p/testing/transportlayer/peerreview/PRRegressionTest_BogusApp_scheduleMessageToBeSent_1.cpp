// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp_scheduleMessageToBeSent_1.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1(PRRegressionTest_BogusApp *PRRegressionTest_BogusApp_this, bool reschedule)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_BogusApp_this(PRRegressionTest_BogusApp_this)
    , reschedule(reschedule)
{
    clinit();
    ctor();
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1::toString()
{
    return ::java::lang::StringBuilder().append(u"SendMessageTask "_j)->append(scheduledExecutionTime())->toString();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1::run()
{
    PRRegressionTest_BogusApp_this->sendMessage();
    if(reschedule)
        PRRegressionTest_BogusApp_this->scheduleMessageToBeSent();

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_scheduleMessageToBeSent_1::getClass0()
{
    return class_();
}

