// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_TestCommand.hpp>

struct default_init_tag;

class rice::p2p::past::testing::RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1
    : public RawPastRegrTest_TestCommand
{

public:
    typedef RawPastRegrTest_TestCommand super;
    void receive(::java::lang::Object* result) /* throws(Exception) */ override;

    // Generated

public: /* protected */
    RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1(RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1 *RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_this, ::rice::p2p::commonapi::Id* remoteId);

public:
    static ::java::lang::Class *class_();
    RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1 *RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_this;
    ::rice::p2p::commonapi::Id* remoteId;

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
    friend class RawPastRegrTest_TestRouteMessage;
};
