// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java
#include <org/mpisws/p2p/transport/direct/EventSimulator_start_1_run_1_1.hpp>

#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator_start_1.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::direct::EventSimulator_start_1_run_1_1::EventSimulator_start_1_run_1_1(EventSimulator_start_1 *EventSimulator_start_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , EventSimulator_start_1_this(EventSimulator_start_1_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::direct::EventSimulator_start_1_run_1_1::run()
{
    if(!EventSimulator_start_1_this->EventSimulator_this->running)
        return;

    try {
        if(!EventSimulator_start_1_this->EventSimulator_this->simulate()) {
            {
                synchronized synchronized_0(EventSimulator_start_1_this->EventSimulator_this->manager);
                {
                    try {
                        npc(EventSimulator_start_1_this->EventSimulator_this->manager)->wait(100);
                    } catch (::java::lang::InterruptedException* ie) {
                        npc(EventSimulator_start_1_this->EventSimulator_this->logger)->logException(u"BasicNetworkSimulator interrupted."_j, ie);
                    }
                }
            }
        }
        npc(EventSimulator_start_1_this->EventSimulator_this->manager)->invoke(this);
    } catch (::java::lang::InterruptedException* ie) {
        if(npc(EventSimulator_start_1_this->EventSimulator_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(EventSimulator_start_1_this->EventSimulator_this->logger)->logException(u"BasicNetworkSimulator.start()"_j, ie);

        EventSimulator_start_1_this->EventSimulator_this->stop();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_start_1_run_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator_start_1_run_1_1::getClass0()
{
    return class_();
}

