// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>

struct default_init_tag;

class rice::p2p::past::testing::PastRegrTest_TestRouteMessage
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
    PastRegrTest_TestRouteMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message);
protected:
    PastRegrTest_TestRouteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastRegrTest;
    friend class PastRegrTest_PastRegrTest_1;
    friend class PastRegrTest_testRouteRequest_2;
    friend class PastRegrTest_testRouteRequest_2_receive_2_1;
    friend class PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1;
    friend class PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1;
    friend class PastRegrTest_testVersionControl_3;
    friend class PastRegrTest_testVersionControl_3_receive_3_1;
    friend class PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1;
    friend class PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1;
    friend class PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1;
    friend class PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1;
    friend class PastRegrTest_testFetch_4;
    friend class PastRegrTest_testFetch_4_receive_4_1;
    friend class PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1;
    friend class PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1_receive_4_1_1_1;
    friend class PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1_receive_4_1_1_1_receive_4_1_1_1_1;
    friend class PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1_receive_4_1_1_1_receive_4_1_1_1_1_receive_4_1_1_1_1_1;
    friend class PastRegrTest_testLookupHandles_5;
    friend class PastRegrTest_testLookupHandles_5_receive_5_1;
    friend class PastRegrTest_testLookupHandles_5_receive_5_1_receive_5_1_1;
    friend class PastRegrTest_testLookupHandles_5_receive_5_1_receive_5_1_1_receive_5_1_1_1;
    friend class PastRegrTest_testCaching_6;
    friend class PastRegrTest_testCaching_6_receive_6_1;
    friend class PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1;
    friend class PastRegrTest_testCaching_6_receive_6_1_receive_6_1_1_receive_6_1_1_1;
    friend class PastRegrTest_TestCommand;
    friend class PastRegrTest_TestExceptionCommand;
    friend class PastRegrTest_TestPastContent;
    friend class PastRegrTest_VersionedTestPastContent;
    friend class PastRegrTest_NonOverwritingTestPastContent;
    friend class PastRegrTest_NonMutableTestPastContent;
    friend class PastRegrTest_TestPastContentHandle;
};
