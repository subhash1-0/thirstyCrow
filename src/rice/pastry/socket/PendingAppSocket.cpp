// Generated from /pastry-2.1/src/rice/pastry/socket/PendingAppSocket.java
#include <rice/pastry/socket/PendingAppSocket.hpp>

#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>

rice::pastry::socket::PendingAppSocket::PendingAppSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::PendingAppSocket::PendingAppSocket(int32_t appAddress, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver) 
    : PendingAppSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(appAddress,receiver);
}

void rice::pastry::socket::PendingAppSocket::ctor(int32_t appAddress, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
    super::ctor();
    this->appAddress = appAddress;
    this->receiver = receiver;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::PendingAppSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.PendingAppSocket", 35);
    return c;
}

java::lang::Class* rice::pastry::socket::PendingAppSocket::getClass0()
{
    return class_();
}

