// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::p2p::past::testing::DistPastTest_DistPastTest_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* result) override;
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    DistPastTest_DistPastTest_1(DistPastTest *DistPastTest_this);
    static ::java::lang::Class *class_();
    DistPastTest *DistPastTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DistPastTest;
    friend class DistPastTest_DistPastTest_2;
};
