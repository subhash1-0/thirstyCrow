// Generated from /pastry-2.1/src/rice/environment/logging/HeirarchyLogger.java
#include <rice/environment/logging/HeirarchyLogger.hpp>

rice::environment::logging::HeirarchyLogger::HeirarchyLogger(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::HeirarchyLogger::HeirarchyLogger()
    : HeirarchyLogger(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::logging::HeirarchyLogger::ctor()
{
    super::ctor();
    init();
}

void rice::environment::logging::HeirarchyLogger::init()
{
    useDefault = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::HeirarchyLogger::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.HeirarchyLogger", 40);
    return c;
}

java::lang::Class* rice::environment::logging::HeirarchyLogger::getClass0()
{
    return class_();
}

