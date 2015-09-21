// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2_getBogusApp_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2::PRNonconform2_getBogusApp_2(PRNonconform2 *PRNonconform2_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
    : super(PRNonconform2_this, *static_cast< ::default_init_tag* >(0))
    , PRNonconform2_this(PRNonconform2_this)
{
    clinit();
    ctor(player, tl, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2::notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus)
{
    if(npc(npc(npc(player)->localHandle)->id)->id == 1)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyStatusChange("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u","_j)
            ->append(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getStatusString(newStatus))
            ->append(u")"_j)->toString());

    if(newStatus == STATUS_EXPOSED) {
        if(!npc(id)->equals(static_cast< ::java::lang::Object* >(npc(PRNonconform2_this->aliceHandle)->id))) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"Node not trusted: "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());
            ::java::lang::System::exit(1);
        }
    }
    PRNonconform2_this->addStatusNotification(npc(this->player)->localHandle, id, newStatus);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< PRRegressionTest_IdImpl* >(id), newStatus);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2::getClass0()
{
    return class_();
}

