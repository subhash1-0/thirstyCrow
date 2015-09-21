// Generated from /pastry-2.1/src/rice/pastry/JoinFailedException.java
#include <rice/pastry/JoinFailedException.hpp>

rice::pastry::JoinFailedException::JoinFailedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::JoinFailedException::JoinFailedException() 
    : JoinFailedException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::JoinFailedException::JoinFailedException(::java::lang::String* message, ::java::lang::Throwable* cause) 
    : JoinFailedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(message,cause);
}

rice::pastry::JoinFailedException::JoinFailedException(::java::lang::String* message) 
    : JoinFailedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(message);
}

rice::pastry::JoinFailedException::JoinFailedException(::java::lang::Throwable* cause) 
    : JoinFailedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(cause);
}

constexpr int64_t rice::pastry::JoinFailedException::serialVersionUID;

void rice::pastry::JoinFailedException::ctor()
{
    super::ctor();
}

void rice::pastry::JoinFailedException::ctor(::java::lang::String* message, ::java::lang::Throwable* cause)
{
    super::ctor(message, cause);
}

void rice::pastry::JoinFailedException::ctor(::java::lang::String* message)
{
    super::ctor(message);
}

void rice::pastry::JoinFailedException::ctor(::java::lang::Throwable* cause)
{
    super::ctor(cause);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::JoinFailedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.JoinFailedException", 31);
    return c;
}

java::lang::Class* rice::pastry::JoinFailedException::getClass0()
{
    return class_();
}

