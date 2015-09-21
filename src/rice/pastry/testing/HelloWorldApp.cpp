// Generated from /pastry-2.1/src/rice/pastry/testing/HelloWorldApp.java
#include <rice/pastry/testing/HelloWorldApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/testing/HelloMsg.hpp>
#include <rice/pastry/testing/HelloWorldApp_HelloAddress.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::HelloWorldApp::HelloWorldApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::HelloWorldApp::HelloWorldApp(::rice::pastry::PastryNode* pn) 
    : HelloWorldApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::testing::HelloWorldApp::init()
{
    msgid = int32_t(0);
}

int32_t& rice::pastry::testing::HelloWorldApp::addr()
{
    clinit();
    return addr_;
}
int32_t rice::pastry::testing::HelloWorldApp::addr_;

void rice::pastry::testing::HelloWorldApp::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn, nullptr, addr_, nullptr);
    init();
    register_();
}

void rice::pastry::testing::HelloWorldApp::sendRndMsg(::rice::environment::random::RandomSource* rng)
{
    auto rndid = ::rice::pastry::Id::makeRandomId(rng);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Sending message from "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u" to random dest "_j)
            ->append(static_cast< ::java::lang::Object* >(rndid))->toString());
    }
    ::rice::pastry::messaging::Message* msg = new HelloMsg(addr_, npc(thePastryNode)->getLocalHandle(), rndid, ++msgid);
    routeMsg(rndid, msg, new ::rice::pastry::routing::SendOptions());
}

int32_t rice::pastry::testing::HelloWorldApp::getAddress()
{
    return addr_;
}

void rice::pastry::testing::HelloWorldApp::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Received "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" at "_j)
            ->append(static_cast< ::java::lang::Object* >(getNodeId()))->toString());
    }
}

bool rice::pastry::testing::HelloWorldApp::enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Enroute "_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" at "_j)
            ->append(static_cast< ::java::lang::Object* >(getNodeId()))->toString());
    }
    return true;
}

void rice::pastry::testing::HelloWorldApp::leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        auto s = ::java::lang::StringBuilder().append(u"In "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u"'s leaf set, "_j)
            ->append(u"node "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
            ->append(u" was "_j)->toString();
        if(wasAdded)
            s = ::java::lang::StringBuilder(s).append(u"added"_j)->toString();
        else
            s = ::java::lang::StringBuilder(s).append(u"removed"_j)->toString();
        npc(::java::lang::System::out())->println(s);
    }
}

void rice::pastry::testing::HelloWorldApp::routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        auto s = ::java::lang::StringBuilder().append(u"In "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u"'s route set, "_j)
            ->append(u"node "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
            ->append(u" was "_j)->toString();
        if(wasAdded)
            s = ::java::lang::StringBuilder(s).append(u"added"_j)->toString();
        else
            s = ::java::lang::StringBuilder(s).append(u"removed"_j)->toString();
        npc(::java::lang::System::out())->println(s);
    }
}

void rice::pastry::testing::HelloWorldApp::notifyReady()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u" ready, waking up any clients"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::HelloWorldApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.HelloWorldApp", 33);
    return c;
}

void rice::pastry::testing::HelloWorldApp::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        addr_ = HelloWorldApp_HelloAddress::getCode();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::HelloWorldApp::getClass0()
{
    return class_();
}

