// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/deterministicsimulator/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    int32_t i {  };

public:
    void run() override;

    // Generated
    DirectTutorial_scheduleDeliveryTask_2(DirectTutorial *DirectTutorial_this, ::rice::pastry::NodeIdFactory* nidFactory);
    static ::java::lang::Class *class_();

private:
    void init();
    DirectTutorial *DirectTutorial_this;
    ::rice::pastry::NodeIdFactory* nidFactory;
    virtual ::java::lang::Class* getClass0();
    friend class DirectTutorial;
    friend class DirectTutorial_scheduleBootTask_1;
    friend class DirectTutorial_scheduleBootTask_1_run_1_1;
    friend class DirectTutorial_scheduleDeliveryTask_3;
};
