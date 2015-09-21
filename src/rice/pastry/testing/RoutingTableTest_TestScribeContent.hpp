// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest_TestScribeContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeContent
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::scribe::Topic* topic {  };
    int32_t num {  };
protected:
    void ctor(::rice::p2p::scribe::Topic* topic, int32_t num);

public:
    bool equals(::java::lang::Object* o) override;
    ::java::lang::String* toString() override;

    // Generated
    RoutingTableTest_TestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num);
protected:
    RoutingTableTest_TestScribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTableTest;
    friend class RoutingTableTest_startLoggerTask_1;
    friend class RoutingTableTest_startLoggerTask_2;
    friend class RoutingTableTest_CreatorTimerTask;
    friend class RoutingTableTest_createNode_3;
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
