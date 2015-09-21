// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp_sendMessage_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Thread.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_sendMessage_2::PRRegressionTest_BogusApp_sendMessage_2(PRRegressionTest_BogusApp *PRRegressionTest_BogusApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_BogusApp_this(PRRegressionTest_BogusApp_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_sendMessage_2::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    npc(PRRegressionTest_BogusApp_this->logger)->log(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(msg))
        ->append(u")"_j)->toString());
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_sendMessage_2::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    npc(npc(PRRegressionTest_BogusApp_this->PRRegressionTest_this->alice)->logger)->log(::java::lang::StringBuilder().append(u"ack("_j)->append(static_cast< ::java::lang::Object* >(msg))
        ->append(u") "_j)
        ->append(static_cast< ::java::lang::Object* >(::java::lang::Thread::currentThread()))->toString());
    if(npc(PRRegressionTest_BogusApp_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(npc(PRRegressionTest_BogusApp_this->PRRegressionTest_this->alice)->logger)->log(::java::lang::StringBuilder().append(u"ack("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_sendMessage_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp_sendMessage_2::getClass0()
{
    return class_();
}

