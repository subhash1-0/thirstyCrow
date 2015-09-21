// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_PRRegressionTest_3.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/Throwable.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>
#include <rice/environment/Environment.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_PRRegressionTest_3::PRRegressionTest_PRRegressionTest_3(PRRegressionTest *PRRegressionTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_this(PRRegressionTest_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_PRRegressionTest_3::run()
{
    try {
        PRRegressionTest_this->buildPlayers(PRRegressionTest_this->env);
        PRRegressionTest_this->setupWitnesses();
    } catch (::java::lang::Exception* ioe) {
        npc(PRRegressionTest_this->env)->destroy();
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_PRRegressionTest_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_PRRegressionTest_3::getClass0()
{
    return class_();
}

