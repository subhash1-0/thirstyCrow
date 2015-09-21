// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribeContent.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/scribe/Topic.hpp>

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

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::ScribeRegrTest_TestScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::ScribeRegrTest_TestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num) 
    : ScribeRegrTest_TestScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(topic,num);
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::ctor(::rice::p2p::scribe::Topic* topic, int32_t num)
{
    super::ctor();
    this->topic = topic;
    this->num = num;
}

bool rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< ScribeRegrTest_TestScribeContent* >(o) != nullptr)) {
        return false;
    }
    return (npc(npc((java_cast< ScribeRegrTest_TestScribeContent* >(o)))->topic)->equals(static_cast< ::java::lang::Object* >(topic)) && npc((java_cast< ScribeRegrTest_TestScribeContent* >(o)))->num == num);
}

java::lang::String* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::toString()
{
    return ::java::lang::StringBuilder().append(u"TestScribeContent("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u", "_j)
        ->append(num)
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.ScribeRegrTest.TestScribeContent", 56);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent::getClass0()
{
    return class_();
}

