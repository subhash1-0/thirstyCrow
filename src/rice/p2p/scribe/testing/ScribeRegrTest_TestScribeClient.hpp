// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>

struct default_init_tag;

class rice::p2p::scribe::testing::ScribeRegrTest_TestScribeClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeClient
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::scribe::Scribe* scribe {  };
    int32_t i {  };
    ::java::util::Vector* publishMessages {  };
    ::java::util::Vector* anycastMessages {  };
    ::java::util::List* topics {  };
    bool acceptAnycast_ {  };
    bool subscribeFailed_ {  };
protected:
    void ctor(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic, int32_t i);
    void ctor(::rice::p2p::scribe::Scribe* scribe, ::java::util::List* topics, int32_t i);

public:
    virtual ::java::util::List* getPublishMessages();
    virtual ::java::util::List* getAnycastMessages();
    virtual void acceptAnycast(bool value);
    bool anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void subscribeFailed(::rice::p2p::scribe::Topic* topic) override;
    virtual bool getSubscribeFailed();
    ::java::lang::String* toString() override;

    // Generated
    ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::scribe::Topic* topic, int32_t i);
    ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe, ::java::util::List* topics, int32_t i);
protected:
    ScribeRegrTest_TestScribeClient(ScribeRegrTest *ScribeRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ScribeRegrTest *ScribeRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeRegrTest;
    friend class ScribeRegrTest_TestScribeContent;
    friend class ScribeRegrTest_TestRouteMessage;
    friend class ScribeRegrTest_TestScribePolicy;
};
