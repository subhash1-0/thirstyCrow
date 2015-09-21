// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java
#include <org/mpisws/p2p/transport/direct/EventSimulator_stop_2.hpp>

#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>

org::mpisws::p2p::transport::direct::EventSimulator_stop_2::EventSimulator_stop_2(EventSimulator *EventSimulator_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , EventSimulator_this(EventSimulator_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::direct::EventSimulator_stop_2::run()
{
    EventSimulator_this->running = false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_stop_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_stop_2::getClass0()
{
    return class_();
}

