// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>

struct default_init_tag;

class rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeContent
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::scribe::Topic* topic {  };
    int32_t num {  };
protected:
    void ctor(::rice::p2p::scribe::Topic* topic, int32_t num);

public:
    bool equals(::java::lang::Object* o) override;
    ::java::lang::String* toString() override;

    // Generated
    ScribeRegrTest_TestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num);
protected:
    ScribeRegrTest_TestScribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeRegrTest;
    friend class ScribeRegrTest_TestRouteMessage;
    friend class ScribeRegrTest_TestScribeClient;
    friend class ScribeRegrTest_TestScribePolicy;
};
