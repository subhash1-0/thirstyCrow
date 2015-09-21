// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_TestScribeContent.hpp>

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

rice::pastry::testing::RoutingTableTest_TestScribeContent::RoutingTableTest_TestScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::RoutingTableTest_TestScribeContent::RoutingTableTest_TestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num) 
    : RoutingTableTest_TestScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(topic,num);
}

void rice::pastry::testing::RoutingTableTest_TestScribeContent::ctor(::rice::p2p::scribe::Topic* topic, int32_t num)
{
    super::ctor();
    this->topic = topic;
    this->num = num;
}

bool rice::pastry::testing::RoutingTableTest_TestScribeContent::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< RoutingTableTest_TestScribeContent* >(o) != nullptr)) {
        return false;
    }
    return (npc(npc((java_cast< RoutingTableTest_TestScribeContent* >(o)))->topic)->equals(static_cast< ::java::lang::Object* >(topic)) && npc((java_cast< RoutingTableTest_TestScribeContent* >(o)))->num == num);
}

java::lang::String* rice::pastry::testing::RoutingTableTest_TestScribeContent::toString()
{
    return ::java::lang::StringBuilder().append(u"TestScribeContent("_j)->append(static_cast< ::java::lang::Object* >(topic))
        ->append(u", "_j)
        ->append(num)
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_TestScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RoutingTableTest.TestScribeContent", 54);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_TestScribeContent::getClass0()
{
    return class_();
}

