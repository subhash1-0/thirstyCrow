// Generated from /pastry-2.1/src/rice/p2p/multiring/testing/MultiringRegrTest.java
#include <rice/p2p/multiring/testing/MultiringRegrTest_MultiringTestApp.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/multiring/testing/MultiringRegrTest_MultiringTestMessage.hpp>
#include <rice/p2p/multiring/testing/MultiringRegrTest.hpp>

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

rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::MultiringRegrTest_MultiringTestApp(MultiringRegrTest *MultiringRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringRegrTest_this(MultiringRegrTest_this)
{
    clinit();
}

rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::MultiringRegrTest_MultiringTestApp(MultiringRegrTest *MultiringRegrTest_this, ::rice::p2p::commonapi::Node* node) 
    : MultiringRegrTest_MultiringTestApp(MultiringRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->endpoint = npc(node)->buildEndpoint(this, u"BLAH"_j);
    npc(this->endpoint)->register_();
}

void rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::send(::rice::p2p::commonapi::Id* target)
{
    npc(endpoint)->route(target, static_cast< ::rice::p2p::commonapi::Message* >(new MultiringRegrTest_MultiringTestMessage(npc(endpoint)->getId())), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

bool rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"RECEIVED MESSSAGE FROM "_j)->append(static_cast< ::java::lang::Object* >(npc((java_cast< MultiringRegrTest_MultiringTestMessage* >(message)))->source))
        ->append(u" FOR TARGET "_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u" AT NODE "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString());
}

void rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.testing.MultiringRegrTest.MultiringTestApp", 61);
    return c;
}

java::lang::Class* rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp::getClass0()
{
    return class_();
}

