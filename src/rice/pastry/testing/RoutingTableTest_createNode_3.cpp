// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_createNode_3.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Observable.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::RoutingTableTest_createNode_3::RoutingTableTest_createNode_3(RoutingTableTest *RoutingTableTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_createNode_3::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Observing "_j)->append(static_cast< ::java::lang::Object* >(o))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(arg))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_3::getClass0()
{
    return class_();
}

