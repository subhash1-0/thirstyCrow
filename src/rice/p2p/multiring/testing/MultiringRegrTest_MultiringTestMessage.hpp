// Generated from /pastry-2.1/src/rice/p2p/multiring/testing/MultiringRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Id* source {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* source);

public:
    int32_t getPriority() override;

    // Generated
    MultiringRegrTest_MultiringTestMessage(::rice::p2p::commonapi::Id* source);
protected:
    MultiringRegrTest_MultiringTestMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringRegrTest;
    friend class MultiringRegrTest_MultiringTestApp;
};
