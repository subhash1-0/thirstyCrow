// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java

#pragma once

#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::EventSimulator_stop_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    EventSimulator_stop_2(EventSimulator *EventSimulator_this);
    static ::java::lang::Class *class_();
    EventSimulator *EventSimulator_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EventSimulator;
    friend class EventSimulator_start_1;
    friend class EventSimulator_start_1_run_1_1;
};
