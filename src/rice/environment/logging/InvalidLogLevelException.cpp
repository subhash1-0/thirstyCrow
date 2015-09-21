// Generated from /pastry-2.1/src/rice/environment/logging/InvalidLogLevelException.java
#include <rice/environment/logging/InvalidLogLevelException.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

rice::environment::logging::InvalidLogLevelException::InvalidLogLevelException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::InvalidLogLevelException::InvalidLogLevelException(::java::lang::String* key, ::java::lang::String* val) 
    : InvalidLogLevelException(*static_cast< ::default_init_tag* >(0))
{
    ctor(key,val);
}

void rice::environment::logging::InvalidLogLevelException::ctor(::java::lang::String* key, ::java::lang::String* val)
{
    super::ctor(::java::lang::StringBuilder().append(val)->append(u" is not an apropriate value for "_j)
        ->append(key)
        ->append(u". Must be an integer or ALL,OFF,SEVERE,WARNING,INFO,CONFIG,FINE,FINER,FINEST"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::InvalidLogLevelException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.InvalidLogLevelException", 49);
    return c;
}

java::lang::Class* rice::environment::logging::InvalidLogLevelException::getClass0()
{
    return class_();
}

