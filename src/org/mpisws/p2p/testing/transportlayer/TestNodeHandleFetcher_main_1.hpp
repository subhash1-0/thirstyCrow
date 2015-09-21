// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::pastry::NodeHandle* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    TestNodeHandleFetcher_main_1();
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TestNodeHandleFetcher;
};
