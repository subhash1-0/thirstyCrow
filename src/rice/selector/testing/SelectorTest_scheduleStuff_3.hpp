// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/selector/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::selector::testing::SelectorTest_scheduleStuff_3
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    SelectorTest_scheduleStuff_3(int64_t i1Start);
    static ::java::lang::Class *class_();
    int64_t i1Start;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SelectorTest;
    friend class SelectorTest_scheduleRepeated_1;
    friend class SelectorTest_scheduleStuff_2;
};
