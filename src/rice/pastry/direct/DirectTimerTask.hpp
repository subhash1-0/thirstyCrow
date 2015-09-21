// Generated from /pastry-2.1/src/rice/pastry/direct/DirectTimerTask.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectTimerTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    MessageDelivery* md {  };
protected:
    void ctor(MessageDelivery* md, int64_t nextExecutionTime, int32_t period, bool fixed);
    void ctor(MessageDelivery* md, int64_t nextExecutionTime, int32_t period);
    void ctor(MessageDelivery* md, int64_t nextExecutionTime);

public:
    void run() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime, int32_t period, bool fixed);
    DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime, int32_t period);
    DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime);
protected:
    DirectTimerTask(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
