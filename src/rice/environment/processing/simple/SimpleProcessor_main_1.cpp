// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java
#include <rice/environment/processing/simple/SimpleProcessor_main_1.hpp>

#include <java/lang/InterruptedException.hpp>
#include <java/lang/Thread.hpp>

rice::environment::processing::simple::SimpleProcessor_main_1::SimpleProcessor_main_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

java::lang::Object* rice::environment::processing::simple::SimpleProcessor_main_1::execute()
{
    try {
        ::java::lang::Thread::sleep(1000);
    } catch (::java::lang::InterruptedException* ie) {
    }
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_1::getClass0()
{
    return class_();
}

