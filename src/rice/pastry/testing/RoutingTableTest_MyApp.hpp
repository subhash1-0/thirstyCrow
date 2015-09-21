// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest_MyApp
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::Node* node {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual ::rice::p2p::commonapi::Node* getNode();
    virtual void routeMyMsg(::rice::p2p::commonapi::Id* id);
    virtual void routeMyMsgDirect(::rice::pastry::NodeHandle* nh);
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    ::java::lang::String* toString() override;

    // Generated
    RoutingTableTest_MyApp(RoutingTableTest *RoutingTableTest_this, ::rice::p2p::commonapi::Node* node);
protected:
    RoutingTableTest_MyApp(RoutingTableTest *RoutingTableTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    RoutingTableTest *RoutingTableTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTableTest;
    friend class RoutingTableTest_startLoggerTask_1;
    friend class RoutingTableTest_startLoggerTask_2;
    friend class RoutingTableTest_CreatorTimerTask;
    friend class RoutingTableTest_TestScribeContent;
    friend class RoutingTableTest_createNode_3;
    friend class RoutingTableTest_createNode_4;
    friend class RoutingTableTest_createNode_5;
    friend class RoutingTableTest_finishNode_6;
    friend class RoutingTableTest_finishNode_6_6_1;
    friend class RoutingTableTest_finishNode_7;
    friend class RoutingTableTest_testLeafSets_8;
    friend class RoutingTableTest_TestScribeClient;
    friend class RoutingTableTest_main_9;
};
