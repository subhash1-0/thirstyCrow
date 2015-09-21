// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_finishNode_6_6_1.hpp>

#include <rice/pastry/testing/RoutingTableTest_finishNode_6.hpp>

rice::pastry::testing::RoutingTableTest_finishNode_6_6_1::RoutingTableTest_finishNode_6_6_1(RoutingTableTest_finishNode_6 *RoutingTableTest_finishNode_6_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_finishNode_6_this(RoutingTableTest_finishNode_6_this)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_finishNode_6_6_1::destroy()
{
    RoutingTableTest_finishNode_6_this->cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_6_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_6_6_1::getClass0()
{
    return class_();
}

