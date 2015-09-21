// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_testLeafSets_8.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

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

rice::pastry::testing::RoutingTableTest_testLeafSets_8::RoutingTableTest_testLeafSets_8(RoutingTableTest *RoutingTableTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
    ctor();
}

int32_t rice::pastry::testing::RoutingTableTest_testLeafSets_8::compare(::rice::pastry::PastryNode* one, ::rice::pastry::PastryNode* two)
{
    auto n1 = java_cast< ::rice::pastry::PastryNode* >(one);
    auto n2 = java_cast< ::rice::pastry::PastryNode* >(two);
    return npc(npc(n1)->getId())->compareTo(npc(n2)->getId());
}

int32_t rice::pastry::testing::RoutingTableTest_testLeafSets_8::compare(::java::lang::Object* o1, ::java::lang::Object* o2)
{ 
    return compare(dynamic_cast< ::rice::pastry::PastryNode* >(o1), dynamic_cast< ::rice::pastry::PastryNode* >(o2));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_testLeafSets_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

bool rice::pastry::testing::RoutingTableTest_testLeafSets_8::equals(::java::lang::Object* obj)
{
    return Object::equals(obj);
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_testLeafSets_8::getClass0()
{
    return class_();
}

