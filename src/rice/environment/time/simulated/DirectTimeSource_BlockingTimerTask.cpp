// Generated from /pastry-2.1/src/rice/environment/time/simulated/DirectTimeSource.java
#include <rice/environment/time/simulated/DirectTimeSource_BlockingTimerTask.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
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
rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::DirectTimeSource_BlockingTimerTask(DirectTimeSource *DirectTimeSource_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectTimeSource_this(DirectTimeSource_this)
{
    clinit();
}

rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::DirectTimeSource_BlockingTimerTask(DirectTimeSource *DirectTimeSource_this)
    : DirectTimeSource_BlockingTimerTask(DirectTimeSource_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::ctor()
{
    super::ctor();
    init();
}

void rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::init()
{
    done = false;
    interrupted = false;
}

void rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::run()
{
    {
        synchronized synchronized_0(DirectTimeSource_this->selectorManager);
        {
            done = true;
            npc(DirectTimeSource_this->selectorManager)->notifyAll();
        }
    }
}

void rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::interrupt()
{
    interrupted = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.time.simulated.DirectTimeSource.BlockingTimerTask", 66);
    return c;
}

java::lang::Class* rice::environment::time::simulated::DirectTimeSource_BlockingTimerTask::getClass0()
{
    return class_();
}

