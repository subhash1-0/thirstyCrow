// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_startLoggerTask_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::RoutingTableTest_startLoggerTask_2::RoutingTableTest_startLoggerTask_2(RoutingTableTest *RoutingTableTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_startLoggerTask_2::run()
{
    npc(RoutingTableTest_this->env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_startLoggerTask_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_startLoggerTask_2::getClass0()
{
    return class_();
}

