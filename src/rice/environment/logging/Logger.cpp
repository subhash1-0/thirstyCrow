// Generated from /pastry-2.1/src/rice/environment/logging/Logger.java
#include <rice/environment/logging/Logger.hpp>

rice::environment::logging::Logger::Logger(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::Logger::Logger()
    : Logger(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::logging::Logger::ctor()
{
    super::ctor();
    init();
}

void rice::environment::logging::Logger::init()
{
    level = int32_t(0);
}

constexpr int32_t rice::environment::logging::Logger::SEVERE;

constexpr int32_t rice::environment::logging::Logger::WARNING;

constexpr int32_t rice::environment::logging::Logger::INFO;

constexpr int32_t rice::environment::logging::Logger::CONFIG;

constexpr int32_t rice::environment::logging::Logger::FINE;

constexpr int32_t rice::environment::logging::Logger::FINER;

constexpr int32_t rice::environment::logging::Logger::FINEST;

constexpr int32_t rice::environment::logging::Logger::ALL;

constexpr int32_t rice::environment::logging::Logger::OFF;

void rice::environment::logging::Logger::log(int32_t priority, ::java::lang::String* message)
{
    if(level <= priority)
        log(message);

}

void rice::environment::logging::Logger::logException(int32_t priority, ::java::lang::String* message, ::java::lang::Throwable* exception)
{
    if(level <= priority)
        logException(message, exception);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::Logger::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.Logger", 31);
    return c;
}

java::lang::Class* rice::environment::logging::Logger::getClass0()
{
    return class_();
}

