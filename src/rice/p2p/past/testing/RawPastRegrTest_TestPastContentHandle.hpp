// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/RawPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::past::testing::RawPastRegrTest_TestPastContentHandle
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::rawserialization::RawPastContentHandle
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandle* handle {  };
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id);

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    RawPastRegrTest_TestPastContentHandle(::rice::p2p::past::Past* past, ::rice::p2p::commonapi::Id* id);
    RawPastRegrTest_TestPastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    RawPastRegrTest_TestPastContentHandle(const ::default_init_tag&);


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
    friend class RawPastRegrTest_TestRouteMessage;
};
