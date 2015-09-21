// Generated from /pastry-2.1/src/rice/environment/logging/simple/SimpleLogManager.java
#include <rice/environment/logging/simple/SimpleLogManager.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/simple/SimpleLogger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params) 
    : SimpleLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params);
}

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat) 
    : SimpleLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params,prefix,dateFormat);
}

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(::rice::environment::params::Parameters* params) 
    : SimpleLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(params);
}

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params) 
    : SimpleLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,params);
}

rice::environment::logging::simple::SimpleLogManager::SimpleLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params) 
    : SimpleLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(timeSource,params);
}

void rice::environment::logging::simple::SimpleLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params)
{
    ctor(stream, timeSource, params, u""_j, nullptr);
}

void rice::environment::logging::simple::SimpleLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat)
{
    super::ctor(stream, timeSource, params, prefix, dateFormat);
}

java::io::PrintStream* rice::environment::logging::simple::SimpleLogManager::getPrintStream()
{
    return ps;
}

rice::environment::params::Parameters* rice::environment::logging::simple::SimpleLogManager::getParameters()
{
    return params;
}

rice::environment::time::TimeSource* rice::environment::logging::simple::SimpleLogManager::getTimeSource()
{
    return time;
}

void rice::environment::logging::simple::SimpleLogManager::ctor(::rice::environment::params::Parameters* params)
{
    ctor(nullptr, new ::rice::environment::time::simple::SimpleTimeSource(), params);
}

void rice::environment::logging::simple::SimpleLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params)
{
    ctor(stream, new ::rice::environment::time::simple::SimpleTimeSource(), params);
}

void rice::environment::logging::simple::SimpleLogManager::ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params)
{
    ctor(nullptr, timeSource, params);
}

rice::environment::logging::Logger* rice::environment::logging::simple::SimpleLogManager::constructLogger(::java::lang::String* clazz, int32_t level, bool useDefault)
{
    return new SimpleLogger(clazz, this, level, useDefault);
}

rice::environment::logging::LogManager* rice::environment::logging::simple::SimpleLogManager::clone(::java::lang::String* detail)
{
    return clone(detail, time);
}

rice::environment::logging::LogManager* rice::environment::logging::simple::SimpleLogManager::clone(::java::lang::String* detail, ::rice::environment::time::TimeSource* ts)
{
    return new SimpleLogManager(ps, ts, params, detail, dateFormat);
}

java::lang::String* rice::environment::logging::simple::SimpleLogManager::toString()
{
    return ::java::lang::StringBuilder().append(u"SimpleLogManager("_j)->append(prefix)
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::simple::SimpleLogManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.simple.SimpleLogManager", 48);
    return c;
}

java::lang::String* rice::environment::logging::simple::SimpleLogManager::getPrefix()
{
    return AbstractLogManager::getPrefix();
}

rice::environment::logging::Logger* rice::environment::logging::simple::SimpleLogManager::getLogger(::java::lang::Class* clazz, ::java::lang::String* instance)
{
    return AbstractLogManager::getLogger(clazz, instance);
}

java::lang::Object* rice::environment::logging::simple::SimpleLogManager::clone()
{
    return super::clone();
}

java::lang::Class* rice::environment::logging::simple::SimpleLogManager::getClass0()
{
    return class_();
}

