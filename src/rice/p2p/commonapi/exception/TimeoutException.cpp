// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/TimeoutException.java
#include <rice/p2p/commonapi/exception/TimeoutException.hpp>

rice::p2p::commonapi::exception::TimeoutException::TimeoutException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::exception::TimeoutException::TimeoutException() 
    : TimeoutException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::exception::TimeoutException::TimeoutException(::java::lang::String* string) 
    : TimeoutException(*static_cast< ::default_init_tag* >(0))
{
    ctor(string);
}

rice::p2p::commonapi::exception::TimeoutException::TimeoutException(::java::lang::Throwable* reason) 
    : TimeoutException(*static_cast< ::default_init_tag* >(0))
{
    ctor(reason);
}

void rice::p2p::commonapi::exception::TimeoutException::ctor()
{
    super::ctor();
}

void rice::p2p::commonapi::exception::TimeoutException::ctor(::java::lang::String* string)
{
    super::ctor(string);
}

void rice::p2p::commonapi::exception::TimeoutException::ctor(::java::lang::Throwable* reason)
{
    super::ctor(reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::exception::TimeoutException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.exception.TimeoutException", 45);
    return c;
}

java::lang::Class* rice::p2p::commonapi::exception::TimeoutException::getClass0()
{
    return class_();
}

