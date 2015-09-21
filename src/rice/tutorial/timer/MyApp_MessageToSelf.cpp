// Generated from /pastry-2.1/src/rice/tutorial/timer/MyApp.java
#include <rice/tutorial/timer/MyApp_MessageToSelf.hpp>

#include <rice/tutorial/timer/MyApp.hpp>

rice::tutorial::timer::MyApp_MessageToSelf::MyApp_MessageToSelf(MyApp *MyApp_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
}

rice::tutorial::timer::MyApp_MessageToSelf::MyApp_MessageToSelf(MyApp *MyApp_this)
    : MyApp_MessageToSelf(MyApp_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t rice::tutorial::timer::MyApp_MessageToSelf::getPriority()
{
    return MAX_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::timer::MyApp_MessageToSelf::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.timer.MyApp.MessageToSelf", 39);
    return c;
}

java::lang::Class* rice::tutorial::timer::MyApp_MessageToSelf::getClass0()
{
    return class_();
}

