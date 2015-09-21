// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory_NullCancellableTask.hpp>

rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::DirectPastryNodeFactory_NullCancellableTask(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::DirectPastryNodeFactory_NullCancellableTask()
    : DirectPastryNodeFactory_NullCancellableTask(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::run()
{
}

bool rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::cancel()
{
    return false;
}

int64_t rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::scheduledExecutionTime()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectPastryNodeFactory.NullCancellableTask", 62);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask::getClass0()
{
    return class_();
}

