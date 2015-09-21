// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>

struct default_init_tag;

class rice::p2p::past::testing::RawPastRegrTest_TestRouteMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::RouteMessage
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::Id* id {  };
    ::rice::p2p::commonapi::NodeHandle* nextHop {  };
    ::rice::p2p::commonapi::Message* message {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message);

public:
    ::rice::p2p::commonapi::Id* getDestinationId() override;
    ::rice::p2p::commonapi::NodeHandle* getNextHopHandle() override;
    ::rice::p2p::commonapi::Message* getMessage() override;
    ::rice::p2p::commonapi::Message* getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) override;
    void setDestinationId(::rice::p2p::commonapi::Id* id) override;
    void setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop) override;
    void setMessage(::rice::p2p::commonapi::Message* message) override;
    void setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message) override;

    // Generated
    RawPastRegrTest_TestRouteMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message);
protected:
    RawPastRegrTest_TestRouteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RawPastRegrTest;
    friend class RawPastRegrTest_RawPastRegrTest_1;
    friend class RawPastRegrTest_processNode_2;
    friend class RawPastRegrTest_processNode_3;
    friend class RawPastRegrTest_testRouteRequest_4;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1_receive_5_1_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1_receive_5_1_1_1_1_receive_5_1_1_1_1_1;
    friend class RawPastRegrTest_testFetch_6;
    friend class RawPastRegrTest_testFetch_6_receive_6_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1_receive_6_1_1_1_1_1;
    friend class RawPastRegrTest_testLookupHandles_7;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1;
    friend class RawPastRegrTest_testCaching_8;
    friend class RawPastRegrTest_testCaching_8_receive_8_1;
    friend class RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1;
    friend class RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1;
    friend class RawPastRegrTest_TestCommand;
    friend class RawPastRegrTest_TestExceptionCommand;
    friend class RawPastRegrTest_TestPastContent;
    friend class RawPastRegrTest_VersionedTestPastContent;
    friend class RawPastRegrTest_NonOverwritingTestPastContent;
    friend class RawPastRegrTest_NonMutableTestPastContent;
    friend class RawPastRegrTest_TestPastContentHandle;
};
