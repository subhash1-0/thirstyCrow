// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1_getBogusApp_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1_getBogusApp_1_init_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::PRNonconform1_getBogusApp_1(PRNonconform1 *PRNonconform1_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
    : super(PRNonconform1_this, *static_cast< ::default_init_tag* >(0))
    , PRNonconform1_this(PRNonconform1_this)
{
    clinit();
    ctor(player, tl, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::init_()
{
    super::init_();
    if(npc(npc(npc(player)->localHandle)->id)->id == 2) {
        npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PRNonconform1_getBogusApp_1_init_1_1(this)), static_cast< int64_t >(int32_t(10000)));
    }
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::messageReceived(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Message received: "_j)->append(::rice::p2p::util::MathUtils::toBase64(npc(m)->array()))->toString());

}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< PRRegressionTest_HandleImpl* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus)
{
    if(npc(npc(npc(player)->localHandle)->id)->id == 2)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyStatusChange("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u","_j)
            ->append(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getStatusString(newStatus))
            ->append(u")"_j)->toString());

    if(newStatus == STATUS_EXPOSED) {
        if(!npc(id)->equals(static_cast< ::java::lang::Object* >(npc(PRNonconform1_this->bobHandle)->id))) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"Node not trusted: "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());
            ::java::lang::System::exit(1);
        }
    }
    PRNonconform1_this->addStatusNotification(npc(this->player)->localHandle, id, newStatus);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< PRRegressionTest_IdImpl* >(id), newStatus);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1::getClass0()
{
    return class_();
}

