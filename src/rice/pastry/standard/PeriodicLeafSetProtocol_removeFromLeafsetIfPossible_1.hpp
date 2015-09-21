// Generated from /pastry-2.1/src/rice/pastry/standard/PeriodicLeafSetProtocol.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::standard::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1(PeriodicLeafSetProtocol *PeriodicLeafSetProtocol_this, ::rice::pastry::NodeHandle* nh);
    static ::java::lang::Class *class_();
    PeriodicLeafSetProtocol *PeriodicLeafSetProtocol_this;
    ::rice::pastry::NodeHandle* nh;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeriodicLeafSetProtocol;
    friend class PeriodicLeafSetProtocol_PLSPMessageDeserializer;
};
