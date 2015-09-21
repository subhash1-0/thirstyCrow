// Generated from /pastry-2.1/src/rice/environment/time/simulated/DirectTimeSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/time/simulated/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    bool done {  };
    bool interrupted {  };

public:
    void run() override;
    virtual void interrupt();

    // Generated
    DirectTimeSource_BlockingTimerTask(DirectTimeSource *DirectTimeSource_this);
protected:
    void ctor();
    DirectTimeSource_BlockingTimerTask(DirectTimeSource *DirectTimeSource_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    DirectTimeSource *DirectTimeSource_this;
    virtual ::java::lang::Class* getClass0();
    friend class DirectTimeSource;
};
