// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribeClient.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest.hpp>

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

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribeRegrTest_this(ScribeRegrTest_this)
{
    clinit();
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic, int32_t i) 
    : ScribeRegrTest_TestScribeClient(ScribeRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(scribe,topic,i);
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe, ::java::util::List* topics, int32_t i) 
    : ScribeRegrTest_TestScribeClient(ScribeRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(scribe,topics,i);
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::ctor(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic, int32_t i)
{
    ctor(scribe, ScribeRegrTest::buildListOf1(topic), i);
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::ctor(::rice::p2p::scribe::Scribe* scribe, ::java::util::List* topics, int32_t i)
{
    super::ctor();
    this->scribe = scribe;
    this->i = i;
    this->topics = topics;
    this->publishMessages = new ::java::util::Vector();
    this->anycastMessages = new ::java::util::Vector();
    this->acceptAnycast_ = false;
    this->subscribeFailed_ = false;
}

java::util::List* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::getPublishMessages()
{
    return publishMessages;
}

java::util::List* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::getAnycastMessages()
{
    return anycastMessages;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::acceptAnycast(bool value)
{
    this->acceptAnycast_ = value;
}

bool rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    if(acceptAnycast_)
        npc(anycastMessages)->add(static_cast< ::java::lang::Object* >(content));

    return acceptAnycast_;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    npc(publishMessages)->add(static_cast< ::java::lang::Object* >(content));
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
    subscribeFailed_ = true;
    npc(scribe)->subscribe(topic, this);
}

bool rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::getSubscribeFailed()
{
    return subscribeFailed_;
}

java::lang::String* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::toString()
{
    if(npc(topics)->size() == 1) {
        return npc(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0)))->toString();
    }
    auto s = u""_j;
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
        {
            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(npc(topics)->toString())->append(u" "_j)->toString())->toString();
        }
    }
    return ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(scribe))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.ScribeRegrTest.TestScribeClient", 55);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient::getClass0()
{
    return class_();
}

