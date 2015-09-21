// Generated from /pastry-2.1/src/rice/p2p/multiring/testing/MultiringRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual void send(::rice::p2p::commonapi::Id* target);
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;

    // Generated
    MultiringRegrTest_MultiringTestApp(MultiringRegrTest *MultiringRegrTest_this, ::rice::p2p::commonapi::Node* node);
protected:
    MultiringRegrTest_MultiringTestApp(MultiringRegrTest *MultiringRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    MultiringRegrTest *MultiringRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringRegrTest;
    friend class MultiringRegrTest_MultiringTestMessage;
};
