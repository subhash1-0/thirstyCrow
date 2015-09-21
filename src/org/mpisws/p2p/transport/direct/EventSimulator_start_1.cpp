// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java
#include <org/mpisws/p2p/transport/direct/EventSimulator_start_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator_start_1_run_1_1.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::EventSimulator_start_1::EventSimulator_start_1(EventSimulator *EventSimulator_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , EventSimulator_this(EventSimulator_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::direct::EventSimulator_start_1::run()
{
    if(EventSimulator_this->running)
        return;

    EventSimulator_this->running = true;
    npc(EventSimulator_this->manager)->invoke(new EventSimulator_start_1_run_1_1(this));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_start_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_start_1::getClass0()
{
    return class_();
}

