// Generated from /pastry-2.1/src/rice/environment/time/simulated/DirectTimeSource.java
#include <rice/environment/time/simulated/DirectTimeSource.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/simulated/DirectTimeSource_BlockingTimerTask.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>

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
rice::environment::time::simulated::DirectTimeSource::DirectTimeSource(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::time::simulated::DirectTimeSource::DirectTimeSource(int64_t time) 
    : DirectTimeSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(time);
}

rice::environment::time::simulated::DirectTimeSource::DirectTimeSource(int64_t time, ::java::lang::String* instance) 
    : DirectTimeSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(time,instance);
}

rice::environment::time::simulated::DirectTimeSource::DirectTimeSource(::rice::environment::params::Parameters* p) 
    : DirectTimeSource(*static_cast< ::default_init_tag* >(0))
{
    ctor(p);
}

void rice::environment::time::simulated::DirectTimeSource::init()
{
    time = int32_t(0);
    logger = nullptr;
    pendingTimers = new ::java::util::HashSet();
}

void rice::environment::time::simulated::DirectTimeSource::ctor(int64_t time)
{
    ctor(time, nullptr);
}

void rice::environment::time::simulated::DirectTimeSource::ctor(int64_t time, ::java::lang::String* instance)
{
    super::ctor();
    init();
    if(time < 0) {
        time = ::java::lang::System::currentTimeMillis();
    } else {
        this->time = time;
    }
    this->instance = instance;
}

void rice::environment::time::simulated::DirectTimeSource::ctor(::rice::environment::params::Parameters* p)
{
    ctor(npc(p)->getLong(u"direct_simulator_start_time"_j));
}

void rice::environment::time::simulated::DirectTimeSource::setLogManager(::rice::environment::logging::LogManager* manager)
{
    logger = npc(manager)->getLogger(DirectTimeSource::class_(), instance);
}

void rice::environment::time::simulated::DirectTimeSource::setSelectorManager(::rice::selector::SelectorManager* sm)
{
    selectorManager = sm;
}

int64_t rice::environment::time::simulated::DirectTimeSource::currentTimeMillis()
{
    return time;
}

void rice::environment::time::simulated::DirectTimeSource::setTime(int64_t newTime)
{
    if(newTime < time) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Attempted to set time from "_j)->append(time)
                ->append(u" to "_j)
                ->append(newTime)
                ->append(u", ignoring."_j)->toString());

        return;
    }
    if((newTime > time) && (npc(logger)->level <= ::rice::environment::logging::Logger::FINER))
        npc(logger)->log(::java::lang::StringBuilder().append(u"DirectTimeSource.setTime("_j)->append(time)
            ->append(u"=>"_j)
            ->append(newTime)
            ->append(u")"_j)->toString());

    time = newTime;
}

void rice::environment::time::simulated::DirectTimeSource::incrementTime(int32_t millis)
{
    setTime(time + millis);
}

void rice::environment::time::simulated::DirectTimeSource::sleep(int64_t delay) /* throws(InterruptedException) */
{
    {
        synchronized synchronized_0(selectorManager);
        {
            auto btt = new DirectTimeSource_BlockingTimerTask(this);
            npc(pendingTimers)->add(static_cast< ::java::lang::Object* >(btt));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"DirectTimeSource.sleep("_j)->append(delay)
                    ->append(u")"_j)->toString());

            npc(npc(selectorManager)->getTimer())->schedule(btt, delay);
            while (!npc(btt)->done) {
                npc(selectorManager)->wait();
                if(npc(btt)->interrupted)
                    throw new ::java::lang::InterruptedException(u"TimeSource destroyed."_j);

            }
            npc(pendingTimers)->remove(static_cast< ::java::lang::Object* >(btt));
        }
    }
}

void rice::environment::time::simulated::DirectTimeSource::destroy()
{
    for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pendingTimers))->iterator(); _i->hasNext(); ) {
        DirectTimeSource_BlockingTimerTask* btt = java_cast< DirectTimeSource_BlockingTimerTask* >(_i->next());
        {
            npc(btt)->interrupt();
        }
    }
    npc(pendingTimers)->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::time::simulated::DirectTimeSource::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.time.simulated.DirectTimeSource", 48);
    return c;
}

java::lang::Class* rice::environment::time::simulated::DirectTimeSource::getClass0()
{
    return class_();
}

