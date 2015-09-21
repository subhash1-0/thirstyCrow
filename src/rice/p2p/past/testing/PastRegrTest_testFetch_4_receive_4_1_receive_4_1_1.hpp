// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestCommand.hpp>

struct default_init_tag;

class rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1
    : public PastRegrTest_TestCommand
{

public:
    typedef PastRegrTest_TestCommand super;
    void receive(::java::lang::Object* result) /* throws(Exception) */ override;

    // Generated

public: /* protected */
    PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1(PastRegrTest_testFetch_4_receive_4_1 *PastRegrTest_testFetch_4_receive_4_1_this, ::rice::p2p::past::PastContent* file1, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContentHandle* handle2, ::rice::p2p::past::PastImpl* remote1, ::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastImpl* remote2);

public:
    static ::java::lang::Class *class_();
    PastRegrTest_testFetch_4_receive_4_1 *PastRegrTest_testFetch_4_receive_4_1_this;
    ::rice::p2p::past::PastContent* file1;
    ::rice::p2p::past::PastContent* file2;
    ::rice::p2p::past::PastImpl* local;
    ::rice::p2p::past::PastContentHandle* handle2;
    ::rice::p2p::past::PastImpl* remote1;
    ::rice::p2p::commonapi::Id* id;
    ::rice::p2p::past::PastImpl* remote2;

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
    friend class PastRegrTest_TestRouteMessage;
};
