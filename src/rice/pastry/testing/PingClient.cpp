// Generated from /pastry-2.1/src/rice/pastry/testing/PingClient.java
#include <rice/pastry/testing/PingClient.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/testing/PingClient_PingAddress.hpp>
#include <rice/pastry/testing/PingMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::PingClient::PingClient(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingClient::PingClient(::rice::pastry::PastryNode* pn) 
    : PingClient(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

int32_t& rice::pastry::testing::PingClient::pingAddress()
{
    clinit();
    return pingAddress_;
}
int32_t rice::pastry::testing::PingClient::pingAddress_;

void rice::pastry::testing::PingClient::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

int32_t rice::pastry::testing::PingClient::getAddress()
{
    return pingAddress_;
}

void rice::pastry::testing::PingClient::sendPing(::rice::pastry::Id* nid)
{
    routeMsg(nid, new PingMessage(pingAddress_, getNodeId(), nid), new ::rice::pastry::routing::SendOptions());
}

void rice::pastry::testing::PingClient::sendTrace(::rice::pastry::Id* nid)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"sending a trace from "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(nid))->toString());
    routeMsg(nid, new PingMessage(pingAddress_, getNodeId(), nid), new ::rice::pastry::routing::SendOptions());
}

void rice::pastry::testing::PingClient::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    npc(::java::lang::System::out())->print(static_cast< ::java::lang::Object* >(msg));
    npc(::java::lang::System::out())->println(u" received"_j);
}

bool rice::pastry::testing::PingClient::enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* from, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt)
{
    npc(::java::lang::System::out())->print(static_cast< ::java::lang::Object* >(msg));
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u" at "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))->toString());
    return true;
}

void rice::pastry::testing::PingClient::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    if(true)
        return;

    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
        ->append(u"'s leaf set"_j)->toString());
    npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"node "_j)->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
        ->append(u" was "_j)->toString());
    if(wasAdded)
        npc(::java::lang::System::out())->println(u"added"_j);
    else
        npc(::java::lang::System::out())->println(u"removed"_j);
}

void rice::pastry::testing::PingClient::routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    if(true)
        return;

    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
        ->append(u"'s route set"_j)->toString());
    npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(u"node "_j)->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
        ->append(u" was "_j)->toString());
    if(wasAdded)
        npc(::java::lang::System::out())->println(u"added"_j);
    else
        npc(::java::lang::System::out())->println(u"removed"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingClient", 30);
    return c;
}

void rice::pastry::testing::PingClient::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        pingAddress_ = PingClient_PingAddress::getCode();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::PingClient::getClass0()
{
    return class_();
}

