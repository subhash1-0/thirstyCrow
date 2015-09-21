// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/selector/testing/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::selector::testing::SelectorTest_scheduleRepeated_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    int64_t lastTime {  };

public:
    void run() override;

    // Generated
    SelectorTest_scheduleRepeated_1(int64_t t1Start, int32_t t1Delay);
    static ::java::lang::Class *class_();

private:
    void init();
    int64_t t1Start;
    int32_t t1Delay;
    virtual ::java::lang::Class* getClass0();
    friend class SelectorTest;
    friend class SelectorTest_scheduleStuff_2;
    friend class SelectorTest_scheduleStuff_3;
};
