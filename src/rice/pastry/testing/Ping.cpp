// Generated from /pastry-2.1/src/rice/pastry/testing/Ping.java
#include <rice/pastry/testing/Ping.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/TestRecord.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/testing/PingAddress.hpp>
#include <rice/pastry/testing/PingMessageNew.hpp>
#include <rice/pastry/testing/PingTestRecord.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::Ping::Ping(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::Ping::Ping(::rice::pastry::PastryNode* pn) 
    : Ping(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

int32_t& rice::pastry::testing::Ping::pingAddress()
{
    clinit();
    return pingAddress_;
}
int32_t rice::pastry::testing::Ping::pingAddress_;

void rice::pastry::testing::Ping::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

int32_t rice::pastry::testing::Ping::getAddress()
{
    return pingAddress_;
}

void rice::pastry::testing::Ping::sendPing(::rice::pastry::Id* nid)
{
    routeMsg(nid, new PingMessageNew(pingAddress_, getNodeHandle(), nid), new ::rice::pastry::routing::SendOptions());
}

void rice::pastry::testing::Ping::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    auto pMsg = java_cast< PingMessageNew* >(msg);
    auto nHops = npc(pMsg)->getHops() - int32_t(1);
    auto fDistance = npc(pMsg)->getDistance();
    double rDistance;
    auto sim = npc((java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc((thePastryNode))->getLocalHandle())))->getSimulator();
    auto tr = java_cast< PingTestRecord* >((npc(sim)->getTestRecord()));
    double dDistance = npc(sim)->networkDelay(java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc(thePastryNode)->getLocalHandle()), java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc(pMsg)->getSender()));
    if(dDistance == 0) {
        rDistance = 0;
    } else {
        rDistance = fDistance / dDistance;
    }
    npc(tr)->addHops(nHops);
    npc(tr)->addDistance(rDistance);
}

bool rice::pastry::testing::Ping::enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* from, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt)
{
    auto pMsg = java_cast< PingMessageNew* >(msg);
    npc(pMsg)->incrHops();
    npc(pMsg)->incrDistance(npc(npc((java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc((thePastryNode))->getLocalHandle())))->getSimulator())->networkDelay(java_cast< ::rice::pastry::direct::DirectNodeHandle* >(npc(thePastryNode)->getLocalHandle()), java_cast< ::rice::pastry::direct::DirectNodeHandle* >(nextHop)));
    return true;
}

void rice::pastry::testing::Ping::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
}

void rice::pastry::testing::Ping::routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::Ping::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.Ping", 24);
    return c;
}

void rice::pastry::testing::Ping::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        pingAddress_ = PingAddress::getCode();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::Ping::getClass0()
{
    return class_();
}

