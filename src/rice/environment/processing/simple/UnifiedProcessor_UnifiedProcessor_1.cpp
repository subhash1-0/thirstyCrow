// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java
#include <rice/environment/processing/simple/UnifiedProcessor_UnifiedProcessor_1.hpp>

#include <rice/environment/processing/simple/UnifiedProcessor.hpp>

rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1::UnifiedProcessor_UnifiedProcessor_1(UnifiedProcessor *UnifiedProcessor_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , UnifiedProcessor_this(UnifiedProcessor_this)
{
    clinit();
    ctor();
}

void rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1::receiveResult(::java::lang::Object* result)
{
}

void rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor_UnifiedProcessor_1::getClass0()
{
    return class_();
}

