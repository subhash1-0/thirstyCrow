// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest_createNode_3
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Observer
{

public:
    typedef ::java::lang::Object super;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;

    // Generated
    RoutingTableTest_createNode_3(RoutingTableTest *RoutingTableTest_this);
    static ::java::lang::Class *class_();
    RoutingTableTest *RoutingTableTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTableTest;
    friend class RoutingTableTest_startLoggerTask_1;
    friend class RoutingTableTest_startLoggerTask_2;
    friend class RoutingTableTest_CreatorTimerTask;
    friend class RoutingTableTest_TestScribeContent;
    friend class RoutingTableTest_createNode_4;
    friend class RoutingTableTest_createNode_5;
    friend class RoutingTableTest_finishNode_6;
    friend class RoutingTableTest_finishNode_6_6_1;
    friend class RoutingTableTest_finishNode_7;
    friend class RoutingTableTest_testLeafSets_8;
    friend class RoutingTableTest_MyApp;
    friend class RoutingTableTest_TestScribeClient;
    friend class RoutingTableTest_main_9;
};
