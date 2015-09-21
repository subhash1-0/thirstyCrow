// Generated from /pastry-2.1/src/rice/pastry/ExponentialBackoffScheduledMessage.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    ExponentialBackoffScheduledMessage_EBTimerTask(ExponentialBackoffScheduledMessage *ExponentialBackoffScheduledMessage_this);
protected:
    ExponentialBackoffScheduledMessage_EBTimerTask(ExponentialBackoffScheduledMessage *ExponentialBackoffScheduledMessage_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ExponentialBackoffScheduledMessage *ExponentialBackoffScheduledMessage_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ExponentialBackoffScheduledMessage;
};
