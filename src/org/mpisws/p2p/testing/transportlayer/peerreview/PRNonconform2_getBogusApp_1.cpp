// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2_getBogusApp_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::PRNonconform2_getBogusApp_1(PRNonconform2 *PRNonconform2_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
    : super(PRNonconform2_this, *static_cast< ::default_init_tag* >(0))
    , PRNonconform2_this(PRNonconform2_this)
{
    clinit();
    init();
    ctor(player, tl, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::init()
{
    msgNum = int32_t(0);
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::generateMessage()
{
    auto ret = super::generateMessage();
    msgNum++;
    if(msgNum == 3) {
        (*ret)[npc(ret)->length - int32_t(1)]++;
    }
    return ret;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus)
{
    return;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< PRRegressionTest_IdImpl* >(id), newStatus);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_1::getClass0()
{
    return class_();
}

