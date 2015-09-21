// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_startLoggerTask_1.hpp>

#include <rice/pastry/testing/RoutingTableTest.hpp>

rice::pastry::testing::RoutingTableTest_startLoggerTask_1::RoutingTableTest_startLoggerTask_1(RoutingTableTest *RoutingTableTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_startLoggerTask_1::init()
{
    ctr = int32_t(0);
}

void rice::pastry::testing::RoutingTableTest_startLoggerTask_1::run()
{
    RoutingTableTest_this->testRoutingTables(ctr++);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_startLoggerTask_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_startLoggerTask_1::getClass0()
{
    return class_();
}

