// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java

#pragma once

#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::p2p::splitstream::testing::SplitStreamDistTest_main_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    SplitStreamDistTest_main_1(::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    ::rice::environment::Environment* env;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamDistTest;
    friend class SplitStreamDistTest_main_2;
};
