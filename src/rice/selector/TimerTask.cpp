// Generated from /pastry-2.1/src/rice/selector/TimerTask.java
#include <rice/selector/TimerTask.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/time/TimeSource.hpp>
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

rice::selector::TimerTask::TimerTask(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::selector::TimerTask::TimerTask()
    : TimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::selector::TimerTask::ctor()
{
    super::ctor();
    init();
}

void rice::selector::TimerTask::init()
{
    cancelled = false;
    period = -int32_t(1);
    fixedRate = false;
}

bool rice::selector::TimerTask::execute(::rice::environment::time::TimeSource* ts)
{
    if(cancelled)
        return false;

    run();
    if(cancelled)
        return false;

    if(period > 0) {
        if(fixedRate) {
            nextExecutionTime += period;
            return true;
        } else {
            nextExecutionTime = npc(ts)->currentTimeMillis() + period;
            return true;
        }
    } else {
        return false;
    }
}

bool rice::selector::TimerTask::cancel()
{
    if(cancelled) {
        return false;
    }
    if(selector != nullptr) {
        npc(selector)->removeTask(this);
    }
    cancelled = true;
    return true;
}

int64_t rice::selector::TimerTask::scheduledExecutionTime()
{
    return nextExecutionTime;
}

int32_t rice::selector::TimerTask::compareTo(TimerTask* arg0)
{
    auto tt = java_cast< TimerTask* >(arg0);
    if(tt == this)
        return 0;

    auto diff = static_cast< int32_t >((nextExecutionTime - npc(tt)->nextExecutionTime));
    if(diff == 0) {
        diff = seq - npc(tt)->seq;
        if(diff == 0) {
            return ::java::lang::System::identityHashCode(this) < ::java::lang::System::identityHashCode(tt) ? int32_t(1) : -int32_t(1);
        }
    }
    return diff;
}

int32_t rice::selector::TimerTask::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< TimerTask* >(o));
}

bool rice::selector::TimerTask::isCancelled()
{
    return cancelled;
}

void rice::selector::TimerTask::setSelectorManager(SelectorManager* selector)
{
    this->selector = selector;
}

void rice::selector::TimerTask::setNextExecutionTime(int64_t l)
{
    nextExecutionTime = l;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::TimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.TimerTask", 23);
    return c;
}

java::lang::Class* rice::selector::TimerTask::getClass0()
{
    return class_();
}

