// Generated from /pastry-2.1/src/rice/pastry/ExponentialBackoffScheduledMessage.java
#include <rice/pastry/ExponentialBackoffScheduledMessage_EBTimerTask.hpp>

#include <rice/pastry/ExponentialBackoffScheduledMessage.hpp>

rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask::ExponentialBackoffScheduledMessage_EBTimerTask(ExponentialBackoffScheduledMessage *ExponentialBackoffScheduledMessage_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ExponentialBackoffScheduledMessage_this(ExponentialBackoffScheduledMessage_this)
{
    clinit();
}

rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask::ExponentialBackoffScheduledMessage_EBTimerTask(ExponentialBackoffScheduledMessage *ExponentialBackoffScheduledMessage_this)
    : ExponentialBackoffScheduledMessage_EBTimerTask(ExponentialBackoffScheduledMessage_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask::run()
{
    ExponentialBackoffScheduledMessage_this->run();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.ExponentialBackoffScheduledMessage.EBTimerTask", 58);
    return c;
}

java::lang::Class* rice::pastry::ExponentialBackoffScheduledMessage_EBTimerTask::getClass0()
{
    return class_();
}

