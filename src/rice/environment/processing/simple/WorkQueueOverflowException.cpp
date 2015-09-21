// Generated from /pastry-2.1/src/rice/environment/processing/simple/WorkQueueOverflowException.java
#include <rice/environment/processing/simple/WorkQueueOverflowException.hpp>

rice::environment::processing::simple::WorkQueueOverflowException::WorkQueueOverflowException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::WorkQueueOverflowException::WorkQueueOverflowException()
    : WorkQueueOverflowException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::WorkQueueOverflowException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.WorkQueueOverflowException", 61);
    return c;
}

java::lang::Class* rice::environment::processing::simple::WorkQueueOverflowException::getClass0()
{
    return class_();
}

