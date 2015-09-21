// Generated from /pastry-2.1/src/rice/pastry/direct/DeliveryTimerTask.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::direct::DeliveryTimerTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    ::org::mpisws::p2p::transport::direct::Delivery* md {  };
protected:
    void ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, bool fixed, int32_t seq);
    void ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, int32_t seq);
    void ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t seq);

public:
    void run() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, bool fixed, int32_t seq);
    DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, int32_t seq);
    DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t seq);
protected:
    DeliveryTimerTask(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
