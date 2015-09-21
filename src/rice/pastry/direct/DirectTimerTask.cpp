// Generated from /pastry-2.1/src/rice/pastry/direct/DirectTimerTask.java
#include <rice/pastry/direct/DirectTimerTask.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/direct/MessageDelivery.hpp>

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

rice::pastry::direct::DirectTimerTask::DirectTimerTask(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectTimerTask::DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime, int32_t period, bool fixed) 
    : DirectTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime,period,fixed);
}

rice::pastry::direct::DirectTimerTask::DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime, int32_t period) 
    : DirectTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime,period);
}

rice::pastry::direct::DirectTimerTask::DirectTimerTask(MessageDelivery* md, int64_t nextExecutionTime) 
    : DirectTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime);
}

void rice::pastry::direct::DirectTimerTask::ctor(MessageDelivery* md, int64_t nextExecutionTime, int32_t period, bool fixed)
{
    super::ctor();
    this->md = md;
    setNextExecutionTime(nextExecutionTime);
    this->period = period;
    this->fixedRate = fixed;
}

void rice::pastry::direct::DirectTimerTask::ctor(MessageDelivery* md, int64_t nextExecutionTime, int32_t period)
{
    ctor(md, nextExecutionTime, period, false);
}

void rice::pastry::direct::DirectTimerTask::ctor(MessageDelivery* md, int64_t nextExecutionTime)
{
    ctor(md, nextExecutionTime, -int32_t(1), false);
}

void rice::pastry::direct::DirectTimerTask::run()
{
    npc(md)->deliver();
}

java::lang::String* rice::pastry::direct::DirectTimerTask::toString()
{
    return ::java::lang::StringBuilder().append(u"DirectTT for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(md)->msg)))
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(md)->node)))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectTimerTask", 34);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectTimerTask::getClass0()
{
    return class_();
}

