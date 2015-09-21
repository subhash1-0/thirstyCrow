// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/NodeIsDeadException.java
#include <rice/p2p/commonapi/exception/NodeIsDeadException.hpp>

rice::p2p::commonapi::exception::NodeIsDeadException::NodeIsDeadException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::exception::NodeIsDeadException::NodeIsDeadException() 
    : NodeIsDeadException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::commonapi::exception::NodeIsDeadException::ctor()
{
    super::ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::exception::NodeIsDeadException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.exception.NodeIsDeadException", 48);
    return c;
}

java::lang::Class* rice::p2p::commonapi::exception::NodeIsDeadException::getClass0()
{
    return class_();
}

