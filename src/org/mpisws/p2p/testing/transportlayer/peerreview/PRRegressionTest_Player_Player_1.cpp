// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player_Player_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <rice/environment/Environment.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_Player_1::PRRegressionTest_Player_Player_1(PRRegressionTest_Player *PRRegressionTest_Player_this, ::rice::environment::Environment* env2)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_Player_this(PRRegressionTest_Player_this)
    , env2(env2)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_Player_1::run()
{
    try {
        npc(PRRegressionTest_Player_this->pr)->init_(npc(PRRegressionTest_Player_this->localHandle)->name);
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
        npc(env2)->destroy();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_Player_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_Player_1::getClass0()
{
    return class_();
}

