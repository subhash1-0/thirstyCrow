// Generated from /pastry-2.1/src/rice/pastry/socket/TransportLayerNodeHandle.java
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

rice::pastry::socket::TransportLayerNodeHandle::TransportLayerNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::TransportLayerNodeHandle::TransportLayerNodeHandle()
    : TransportLayerNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::TransportLayerNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.TransportLayerNodeHandle", 43);
    return c;
}

java::lang::Class* rice::pastry::socket::TransportLayerNodeHandle::getClass0()
{
    return class_();
}

