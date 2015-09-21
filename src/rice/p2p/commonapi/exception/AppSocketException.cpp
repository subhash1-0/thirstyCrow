// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/AppSocketException.java
#include <rice/p2p/commonapi/exception/AppSocketException.hpp>

#include <java/lang/Throwable.hpp>

rice::p2p::commonapi::exception::AppSocketException::AppSocketException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::exception::AppSocketException::AppSocketException() 
    : AppSocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::exception::AppSocketException::AppSocketException(::java::lang::Throwable* reason) 
    : AppSocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor(reason);
}

rice::p2p::commonapi::exception::AppSocketException::AppSocketException(::java::lang::String* string) 
    : AppSocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor(string);
}

void rice::p2p::commonapi::exception::AppSocketException::ctor()
{
    super::ctor();
}

void rice::p2p::commonapi::exception::AppSocketException::ctor(::java::lang::Throwable* reason)
{
    super::ctor();
    this->reason_ = reason;
}

void rice::p2p::commonapi::exception::AppSocketException::ctor(::java::lang::String* string)
{
    super::ctor(string);
}

java::lang::Throwable* rice::p2p::commonapi::exception::AppSocketException::reason()
{
    return reason_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::exception::AppSocketException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.exception.AppSocketException", 47);
    return c;
}

java::lang::Class* rice::p2p::commonapi::exception::AppSocketException::getClass0()
{
    return class_();
}

