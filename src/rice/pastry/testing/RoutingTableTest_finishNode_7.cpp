// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_finishNode_7.hpp>

#include <rice/pastry/testing/RoutingTableTest.hpp>

rice::pastry::testing::RoutingTableTest_finishNode_7::RoutingTableTest_finishNode_7(RoutingTableTest *RoutingTableTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_finishNode_7::run()
{
    if(RoutingTableTest_this->useScribe) {
        RoutingTableTest_this->sendSomeScribeMessages();
    } else {
        RoutingTableTest_this->sendSomeMessages();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_7::getClass0()
{
    return class_();
}

