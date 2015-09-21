// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java
#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator_start_1.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator_stop_2.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

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
org::mpisws::p2p::transport::direct::EventSimulator::EventSimulator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::direct::EventSimulator::EventSimulator(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, ::rice::environment::logging::Logger* logger) 
    : EventSimulator(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,random,logger);
}

void org::mpisws::p2p::transport::direct::EventSimulator::init()
{
    isDirectTimeSource = false;
    maxSpeedRequestSystemTime = int32_t(0);
    maxSpeedRequestSimTime = int32_t(0);
    maxSpeed = 0.0f;
    printedDirectTimeSourceWarning = false;
    running = false;
}

void org::mpisws::p2p::transport::direct::EventSimulator::ctor(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, ::rice::environment::logging::Logger* logger)
{
    super::ctor();
    init();
    this->environment = env;
    this->random = random;
    this->logger = logger;
    manager = npc(environment)->getSelectorManager();
    timeSource = npc(env)->getTimeSource();
    if(dynamic_cast< ::rice::environment::time::simulated::DirectTimeSource* >(timeSource) != nullptr)
        isDirectTimeSource = true;

    npc(manager)->setSelect(false);
}

void org::mpisws::p2p::transport::direct::EventSimulator::setMaxSpeed(float speed)
{
    if(!isDirectTimeSource) {
        if(!printedDirectTimeSourceWarning) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Invalid TimeSource for setMaxSpeed()/setFullSpeed().  Use Environment.directEnvironment() to construct your Environment."_j);

            printedDirectTimeSourceWarning = true;
        }
    }
    maxSpeedRequestSystemTime = ::java::lang::System::currentTimeMillis();
    maxSpeedRequestSimTime = npc(timeSource)->currentTimeMillis();
    maxSpeed = speed;
}

void org::mpisws::p2p::transport::direct::EventSimulator::setFullSpeed()
{
    setMaxSpeed(-1.0f);
}

bool org::mpisws::p2p::transport::direct::EventSimulator::simulate() /* throws(InterruptedException) */
{
    if(!isDirectTimeSource)
        return true;

    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::RuntimeException(u"Must be on selector thread"_j);

    {
        synchronized synchronized_0(manager);
        {
            auto scheduledExecutionTime = npc(manager)->getNextTaskExecutionTime();
            if(scheduledExecutionTime < 0) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(u"taskQueue is empty"_j);

                return false;
            }
            if(scheduledExecutionTime > npc(timeSource)->currentTimeMillis()) {
                auto newSimTime = scheduledExecutionTime;
                if(maxSpeed > 0) {
                    auto sysTime = ::java::lang::System::currentTimeMillis();
                    auto sysTimeDiff = sysTime - maxSpeedRequestSystemTime;
                    auto maxSimTime = static_cast< int64_t >((maxSpeedRequestSimTime + (sysTimeDiff * maxSpeed)));
                    if(maxSimTime < newSimTime) {
                        auto neededSysDelay = static_cast< int64_t >(((newSimTime - maxSimTime) / maxSpeed));
                        if(neededSysDelay >= 1) {
                            npc(manager)->wait(neededSysDelay);
                            auto now = ::java::lang::System::currentTimeMillis();
                            auto delay = now - sysTime;
                            if(delay < neededSysDelay)
                                return true;

                        }
                    }
                }
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"the time is now "_j)->append(newSimTime)->toString());

                npc((java_cast< ::rice::environment::time::simulated::DirectTimeSource* >(timeSource)))->setTime(newSimTime);
            }
        }
    }
    return true;
}

void org::mpisws::p2p::transport::direct::EventSimulator::start()
{
    npc(manager)->invoke(new EventSimulator_start_1(this));
}

void org::mpisws::p2p::transport::direct::EventSimulator::stop()
{
    npc(manager)->invoke(new EventSimulator_stop_2(this));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.EventSimulator", 46);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::EventSimulator::getClass0()
{
    return class_();
}

