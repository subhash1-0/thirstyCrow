// Generated from /pastry-2.1/src/rice/pastry/direct/DeliveryTimerTask.java
#include <rice/pastry/direct/DeliveryTimerTask.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/direct/Delivery.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::DeliveryTimerTask::DeliveryTimerTask(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DeliveryTimerTask::DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, bool fixed, int32_t seq) 
    : DeliveryTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime,period,fixed,seq);
}

rice::pastry::direct::DeliveryTimerTask::DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, int32_t seq) 
    : DeliveryTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime,period,seq);
}

rice::pastry::direct::DeliveryTimerTask::DeliveryTimerTask(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t seq) 
    : DeliveryTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(md,nextExecutionTime,seq);
}

void rice::pastry::direct::DeliveryTimerTask::ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, bool fixed, int32_t seq)
{
    super::ctor();
    this->md = md;
    setNextExecutionTime(nextExecutionTime);
    this->period = period;
    this->fixedRate = fixed;
    this->seq = seq;
}

void rice::pastry::direct::DeliveryTimerTask::ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t period, int32_t seq)
{
    ctor(md, nextExecutionTime, -int32_t(1), false, seq);
}

void rice::pastry::direct::DeliveryTimerTask::ctor(::org::mpisws::p2p::transport::direct::Delivery* md, int64_t nextExecutionTime, int32_t seq)
{
    ctor(md, nextExecutionTime, -int32_t(1), false, seq);
}

void rice::pastry::direct::DeliveryTimerTask::run()
{
    npc(md)->deliver();
}

java::lang::String* rice::pastry::direct::DeliveryTimerTask::toString()
{
    return ::java::lang::StringBuilder().append(u"DeliveryTT for "_j)->append(static_cast< ::java::lang::Object* >(md))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DeliveryTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DeliveryTimerTask", 36);
    return c;
}

java::lang::Class* rice::pastry::direct::DeliveryTimerTask::getClass0()
{
    return class_();
}

