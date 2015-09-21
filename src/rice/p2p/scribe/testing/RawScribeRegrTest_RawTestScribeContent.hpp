// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/RawScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

struct default_init_tag;

class rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent
    : public ScribeRegrTest_TestScribeContent
    , public virtual ::rice::p2p::scribe::rawserialization::RawScribeContent
{

public:
    typedef ScribeRegrTest_TestScribeContent super;
    static constexpr int16_t TYPE { int16_t(1) };
protected:
    void ctor(::rice::p2p::scribe::Topic* topic, int32_t num);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    RawScribeRegrTest_RawTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num);
    RawScribeRegrTest_RawTestScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    RawScribeRegrTest_RawTestScribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RawScribeRegrTest;
    friend class RawScribeRegrTest_processNode_1;
};
