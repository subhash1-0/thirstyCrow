// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getCommonAPITransportLayer_8.hpp>

#include <rice/pastry/Id.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_8::SocketPastryNodeFactory_getCommonAPITransportLayer_8(SocketPastryNodeFactory *SocketPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Id* rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_8::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return ::rice::pastry::Id::build(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getCommonAPITransportLayer_8::getClass0()
{
    return class_();
}

