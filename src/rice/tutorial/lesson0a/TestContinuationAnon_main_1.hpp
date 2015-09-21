// Generated from /pastry-2.1/src/rice/tutorial/lesson0a/TestContinuationAnon.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lesson0a/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::lesson0a::TestContinuationAnon_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::p2p::past::PastContent* pc);
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    TestContinuationAnon_main_1();
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TestContinuationAnon;
};
