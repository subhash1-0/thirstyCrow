// Generated from /pastry-2.1/src/rice/environment/logging/LogOutputStream.java
#include <rice/environment/logging/LogOutputStream.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::logging::LogOutputStream::LogOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::LogOutputStream::LogOutputStream(::rice::environment::Environment* env, int32_t level) 
    : LogOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,level);
}

rice::environment::logging::LogOutputStream::LogOutputStream(::rice::environment::Environment* env, int32_t level, ::java::lang::String* instance) 
    : LogOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,level,instance);
}

constexpr int32_t rice::environment::logging::LogOutputStream::BUFFER_SIZE;

void rice::environment::logging::LogOutputStream::ctor(::rice::environment::Environment* env, int32_t level)
{
    ctor(env, level, u""_j);
}

void rice::environment::logging::LogOutputStream::ctor(::rice::environment::Environment* env, int32_t level, ::java::lang::String* instance)
{
    super::ctor();
    logger = npc(npc(env)->getLogManager())->getLogger(LogOutputStream::class_(), instance);
    buffer = new ::int8_tArray(BUFFER_SIZE);
    offset = 0;
    this->level = level;
}

void rice::environment::logging::LogOutputStream::write(int32_t b) /* throws(IOException) */
{
    if(b == u'\u000a') {
        if((offset > 0) && ((*buffer)[offset - int32_t(1)] == u'\u000d'))
            offset--;

        flush();
        return;
    }
    if((offset > 0) && (*buffer)[offset - int32_t(1)] == u'\u000d') {
        offset--;
        flush();
    }
    if(offset == npc(buffer)->length - int32_t(1))
        flush();

    (*buffer)[offset++] = static_cast< int8_t >((b & int32_t(255)));
}

void rice::environment::logging::LogOutputStream::flush()
{
    if(offset == 0)
        return;

    if(npc(logger)->level <= level)
        npc(logger)->log(new ::java::lang::String(buffer, int32_t(0), offset));

    offset = 0;
}

void rice::environment::logging::LogOutputStream::close()
{
    flush();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::LogOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.LogOutputStream", 40);
    return c;
}

void rice::environment::logging::LogOutputStream::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

void rice::environment::logging::LogOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{
    super::write(arg0, arg1, arg2);
}

java::lang::Class* rice::environment::logging::LogOutputStream::getClass0()
{
    return class_();
}

