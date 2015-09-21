// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::testing::ScribeRegrTest_TestRouteMessage
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
    ScribeRegrTest_TestRouteMessage(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* nextHop, ::rice::p2p::commonapi::Message* message);
protected:
    ScribeRegrTest_TestRouteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeRegrTest;
    friend class ScribeRegrTest_TestScribeContent;
    friend class ScribeRegrTest_TestScribeClient;
    friend class ScribeRegrTest_TestScribePolicy;
};
