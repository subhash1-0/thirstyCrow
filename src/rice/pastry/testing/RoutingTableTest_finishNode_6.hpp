// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest_finishNode_6
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    RoutingTableTest_finishNode_6(RoutingTableTest *RoutingTableTest_this, ::rice::pastry::PastryNode* node);
    static ::java::lang::Class *class_();

private:
    void init();
    RoutingTableTest *RoutingTableTest_this;
    ::rice::pastry::PastryNode* node;
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTableTest;
    friend class RoutingTableTest_startLoggerTask_1;
    friend class RoutingTableTest_startLoggerTask_2;
    friend class RoutingTableTest_CreatorTimerTask;
    friend class RoutingTableTest_TestScribeContent;
    friend class RoutingTableTest_createNode_3;
    friend class RoutingTableTest_createNode_4;
    friend class RoutingTableTest_createNode_5;
    friend class RoutingTableTest_finishNode_6_6_1;
    friend class RoutingTableTest_finishNode_7;
    friend class RoutingTableTest_testLeafSets_8;
    friend class RoutingTableTest_MyApp;
    friend class RoutingTableTest_TestScribeClient;
    friend class RoutingTableTest_main_9;
};
