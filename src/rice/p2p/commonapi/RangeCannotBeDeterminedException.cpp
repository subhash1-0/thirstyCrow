// Generated from /pastry-2.1/src/rice/p2p/commonapi/RangeCannotBeDeterminedException.java
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>

rice::p2p::commonapi::RangeCannotBeDeterminedException::RangeCannotBeDeterminedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::RangeCannotBeDeterminedException::RangeCannotBeDeterminedException() 
    : RangeCannotBeDeterminedException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::RangeCannotBeDeterminedException::RangeCannotBeDeterminedException(::java::lang::String* arg0) 
    : RangeCannotBeDeterminedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

rice::p2p::commonapi::RangeCannotBeDeterminedException::RangeCannotBeDeterminedException(::java::lang::Throwable* arg0) 
    : RangeCannotBeDeterminedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

rice::p2p::commonapi::RangeCannotBeDeterminedException::RangeCannotBeDeterminedException(::java::lang::String* arg0, ::java::lang::Throwable* arg1) 
    : RangeCannotBeDeterminedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0,arg1);
}

void rice::p2p::commonapi::RangeCannotBeDeterminedException::ctor()
{
    super::ctor();
}

void rice::p2p::commonapi::RangeCannotBeDeterminedException::ctor(::java::lang::String* arg0)
{
    super::ctor(arg0);
}

void rice::p2p::commonapi::RangeCannotBeDeterminedException::ctor(::java::lang::Throwable* arg0)
{
    super::ctor(arg0);
}

void rice::p2p::commonapi::RangeCannotBeDeterminedException::ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1)
{
    super::ctor(arg0, arg1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::RangeCannotBeDeterminedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.RangeCannotBeDeterminedException", 51);
    return c;
}

java::lang::Class* rice::p2p::commonapi::RangeCannotBeDeterminedException::getClass0()
{
    return class_();
}

