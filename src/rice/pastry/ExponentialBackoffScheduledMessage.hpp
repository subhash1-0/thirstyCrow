// Generated from /pastry-2.1/src/rice/pastry/ExponentialBackoffScheduledMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/pastry/ScheduledMessage.hpp>

struct default_init_tag;

class rice::pastry::ExponentialBackoffScheduledMessage
    : public ScheduledMessage
{

public:
    typedef ScheduledMessage super;

public: /* package */
    bool cancelled {  };
    ExponentialBackoffScheduledMessage_EBTimerTask* myTask {  };
    ::rice::selector::Timer* timer {  };
    int64_t initialPeriod {  };
    double expBase {  };
    int32_t numTimes {  };
    int64_t lastTime {  };
    int64_t maxTime {  };
protected:
    void ctor(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, int64_t initialPeriod, double expBase, int64_t maxPeriod);
    void ctor(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, double expBase);

private:
    void schedule(int64_t time);

public:
    bool cancel() override;
    void run() override;
    int64_t scheduledExecutionTime() override;

    // Generated
    ExponentialBackoffScheduledMessage(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, int64_t initialPeriod, double expBase, int64_t maxPeriod);
    ExponentialBackoffScheduledMessage(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, double expBase);
protected:
    ExponentialBackoffScheduledMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class ExponentialBackoffScheduledMessage_EBTimerTask;
};
