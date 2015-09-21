// Generated from /pastry-2.1/src/rice/selector/TimerTask.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>

struct default_init_tag;

class rice::selector::TimerTask
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
    , public virtual ::rice::p2p::commonapi::CancellableTask
{

public:
    typedef ::java::lang::Object super;

private:
    int64_t nextExecutionTime {  };

public: /* protected */
    bool cancelled {  };
    int32_t seq {  };
    SelectorManager* selector {  };
    int32_t period {  };
    bool fixedRate {  };
    /*void run(); (already declared) */

public:
    virtual bool execute(::rice::environment::time::TimeSource* ts);
    bool cancel() override;
    int64_t scheduledExecutionTime() override;
    virtual int32_t compareTo(TimerTask* arg0);
    virtual bool isCancelled();
    virtual void setSelectorManager(SelectorManager* selector);

public: /* protected */
    virtual void setNextExecutionTime(int64_t l);

    // Generated

public:
    TimerTask();
protected:
    void ctor();
    TimerTask(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
