// Generated from /pastry-2.1/src/rice/environment/time/simple/SimpleTimeSource.java
#include <rice/environment/time/simple/SimpleTimeSource.hpp>

#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>

rice::environment::time::simple::SimpleTimeSource::SimpleTimeSource(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::time::simple::SimpleTimeSource::SimpleTimeSource() 
    : SimpleTimeSource(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::time::simple::SimpleTimeSource::ctor()
{
    super::ctor();
}

int64_t rice::environment::time::simple::SimpleTimeSource::currentTimeMillis()
{
    return ::java::lang::System::currentTimeMillis();
}

void rice::environment::time::simple::SimpleTimeSource::sleep(int64_t delay) /* throws(InterruptedException) */
{
    ::java::lang::Thread::sleep(delay);
}

void rice::environment::time::simple::SimpleTimeSource::destroy()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::time::simple::SimpleTimeSource::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.time.simple.SimpleTimeSource", 45);
    return c;
}

java::lang::Class* rice::environment::time::simple::SimpleTimeSource::getClass0()
{
    return class_();
}

