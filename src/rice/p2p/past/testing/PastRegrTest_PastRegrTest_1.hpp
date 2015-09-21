// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::p2p::past::testing::PastRegrTest_PastRegrTest_1
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;
    void run() override;

    // Generated
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::String* arg0);

public: /* package */
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1);

public:
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0, ::java::lang::String* arg1);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2);
    PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3);
    static ::java::lang::Class *class_();
    PastRegrTest *PastRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastRegrTest;
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
    friend class PastRegrTest_TestRouteMessage;
};
