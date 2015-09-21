// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/NoReceiverAvailableException.java
#include <rice/p2p/commonapi/exception/NoReceiverAvailableException.hpp>

rice::p2p::commonapi::exception::NoReceiverAvailableException::NoReceiverAvailableException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::exception::NoReceiverAvailableException::NoReceiverAvailableException() 
    : NoReceiverAvailableException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::commonapi::exception::NoReceiverAvailableException::ctor()
{
    super::ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::exception::NoReceiverAvailableException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.exception.NoReceiverAvailableException", 57);
    return c;
}

java::lang::Class* rice::p2p::commonapi::exception::NoReceiverAvailableException::getClass0()
{
    return class_();
}

