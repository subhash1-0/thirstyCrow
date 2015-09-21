// Generated from /pastry-2.1/src/rice/p2p/util/TimerWeakHashMap.java
#include <rice/p2p/util/TimerWeakHashMap_HardLinkTimerTask.hpp>

#include <java/lang/Object.hpp>

rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::TimerWeakHashMap_HardLinkTimerTask(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::TimerWeakHashMap_HardLinkTimerTask(::java::lang::Object* hardLink) 
    : TimerWeakHashMap_HardLinkTimerTask(*static_cast< ::default_init_tag* >(0))
{
    ctor(hardLink);
}

void rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::ctor(::java::lang::Object* hardLink)
{
    super::ctor();
    this->hardLink = hardLink;
}

void rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::run()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.TimerWeakHashMap.HardLinkTimerTask", 48);
    return c;
}

java::lang::Class* rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask::getClass0()
{
    return class_();
}

