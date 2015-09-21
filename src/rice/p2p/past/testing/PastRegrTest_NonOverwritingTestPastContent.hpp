// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_VersionedTestPastContent.hpp>

struct default_init_tag;

class rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent
    : public PastRegrTest_VersionedTestPastContent
{

public:
    typedef PastRegrTest_VersionedTestPastContent super;
protected:
    void ctor(::rice::p2p::commonapi::Id* id, int32_t version);

public:
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;

    // Generated
    PastRegrTest_NonOverwritingTestPastContent(::rice::p2p::commonapi::Id* id, int32_t version);
protected:
    PastRegrTest_NonOverwritingTestPastContent(const ::default_init_tag&);


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
    friend class PastRegrTest_NonMutableTestPastContent;
    friend class PastRegrTest_TestPastContentHandle;
    friend class PastRegrTest_TestRouteMessage;
};
