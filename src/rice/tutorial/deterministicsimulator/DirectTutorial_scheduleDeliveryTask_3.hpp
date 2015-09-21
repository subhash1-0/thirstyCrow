// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/tutorial/deterministicsimulator/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    ::java::util::Iterator* appIterator {  };

public:
    void run() override;

    // Generated
    DirectTutorial_scheduleDeliveryTask_3(DirectTutorial *DirectTutorial_this);
    static ::java::lang::Class *class_();

private:
    void init();
    DirectTutorial *DirectTutorial_this;
    virtual ::java::lang::Class* getClass0();
    friend class DirectTutorial;
    friend class DirectTutorial_scheduleBootTask_1;
    friend class DirectTutorial_scheduleBootTask_1_run_1_1;
    friend class DirectTutorial_scheduleDeliveryTask_2;
};
