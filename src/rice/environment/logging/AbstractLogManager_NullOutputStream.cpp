// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java
#include <rice/environment/logging/AbstractLogManager_NullOutputStream.hpp>

rice::environment::logging::AbstractLogManager_NullOutputStream::AbstractLogManager_NullOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::AbstractLogManager_NullOutputStream::AbstractLogManager_NullOutputStream()
    : AbstractLogManager_NullOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::logging::AbstractLogManager_NullOutputStream::write(int32_t arg0) /* throws(IOException) */
{
}

void rice::environment::logging::AbstractLogManager_NullOutputStream::write(::int8_tArray* buf) /* throws(IOException) */
{
}

void rice::environment::logging::AbstractLogManager_NullOutputStream::write(::int8_tArray* buf, int32_t a, int32_t b) /* throws(IOException) */
{
}

void rice::environment::logging::AbstractLogManager_NullOutputStream::close()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::AbstractLogManager_NullOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.AbstractLogManager.NullOutputStream", 60);
    return c;
}

java::lang::Class* rice::environment::logging::AbstractLogManager_NullOutputStream::getClass0()
{
    return class_();
}

