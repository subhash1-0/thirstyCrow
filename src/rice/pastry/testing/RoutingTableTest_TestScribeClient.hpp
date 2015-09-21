// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest_TestScribeClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeClient
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::scribe::Scribe* scribe {  };
    ::rice::p2p::scribe::Topic* topic {  };
    bool acceptAnycast_ {  };
    bool subscribeFailed_ {  };
protected:
    void ctor(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic);

public:
    virtual void acceptAnycast(bool value);
    bool anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void subscribeFailed(::rice::p2p::scribe::Topic* topic) override;
    virtual bool getSubscribeFailed();

    // Generated
    RoutingTableTest_TestScribeClient(RoutingTableTest *RoutingTableTest_this, ::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic);
protected:
    RoutingTableTest_TestScribeClient(RoutingTableTest *RoutingTableTest_this, const ::default_init_tag&);


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
    friend class RoutingTableTest_MyApp;
    friend class RoutingTableTest_main_9;
};
