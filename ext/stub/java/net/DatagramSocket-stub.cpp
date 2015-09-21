// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/DatagramSocket.hpp>

extern void unimplemented_(const char16_t* name);
java::net::DatagramSocket::DatagramSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::DatagramSocket::DatagramSocket()
    : DatagramSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::net::DatagramSocket::DatagramSocket(DatagramSocketImpl* arg0)
    : DatagramSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::net::DatagramSocket::DatagramSocket(SocketAddress* arg0)
    : DatagramSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::net::DatagramSocket::DatagramSocket(int32_t arg0)
    : DatagramSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::net::DatagramSocket::DatagramSocket(int32_t arg0, InetAddress* arg1)
    : DatagramSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int32_t java::net::DatagramSocket::ST_CONNECTED;
constexpr int32_t java::net::DatagramSocket::ST_CONNECTED_NO_IMPL;
constexpr int32_t java::net::DatagramSocket::ST_NOT_CONNECTED;
java::net::DatagramSocketImplFactory*& java::net::DatagramSocket::factory()
{
    clinit();
    return factory_;
}
java::net::DatagramSocketImplFactory* java::net::DatagramSocket::factory_;
java::lang::Class*& java::net::DatagramSocket::implClass()
{
    clinit();
    return implClass_;
}
java::lang::Class* java::net::DatagramSocket::implClass_;

void ::java::net::DatagramSocket::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::DatagramSocket::ctor()");
}

void ::java::net::DatagramSocket::ctor(DatagramSocketImpl* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::DatagramSocket::ctor(DatagramSocketImpl* arg0)");
}

void ::java::net::DatagramSocket::ctor(SocketAddress* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::DatagramSocket::ctor(SocketAddress* arg0)");
}

void ::java::net::DatagramSocket::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::DatagramSocket::ctor(int32_t arg0)");
}

void ::java::net::DatagramSocket::ctor(int32_t arg0, InetAddress* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::DatagramSocket::ctor(int32_t arg0, InetAddress* arg1)");
}

void java::net::DatagramSocket::bind(SocketAddress* arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::bind(SocketAddress* arg0)");
}

void java::net::DatagramSocket::checkAddress(InetAddress* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::checkAddress(InetAddress* arg0, ::java::lang::String* arg1)");
}

/* private: bool java::net::DatagramSocket::checkFiltering(DatagramPacket* arg0) */
/* private: void java::net::DatagramSocket::checkOldImpl() */
void java::net::DatagramSocket::close()
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::close()");
}

void java::net::DatagramSocket::connect(SocketAddress* arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::connect(SocketAddress* arg0)");
}

void java::net::DatagramSocket::connect(InetAddress* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::connect(InetAddress* arg0, int32_t arg1)");
}

/* private: void java::net::DatagramSocket::connectInternal(InetAddress* arg0, int32_t arg1) */
void java::net::DatagramSocket::createImpl()
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::createImpl()");
}

void java::net::DatagramSocket::disconnect()
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::disconnect()");
}

bool java::net::DatagramSocket::getBroadcast()
{ /* stub */
    unimplemented_(u"bool java::net::DatagramSocket::getBroadcast()");
    return 0;
}

java::nio::channels::DatagramChannel* java::net::DatagramSocket::getChannel()
{ /* stub */
    unimplemented_(u"java::nio::channels::DatagramChannel* java::net::DatagramSocket::getChannel()");
    return 0;
}

java::net::DatagramSocketImpl* java::net::DatagramSocket::getImpl()
{ /* stub */
return impl ; /* getter */
}

java::net::InetAddress* java::net::DatagramSocket::getInetAddress()
{ /* stub */
    unimplemented_(u"java::net::InetAddress* java::net::DatagramSocket::getInetAddress()");
    return 0;
}

java::net::InetAddress* java::net::DatagramSocket::getLocalAddress()
{ /* stub */
    unimplemented_(u"java::net::InetAddress* java::net::DatagramSocket::getLocalAddress()");
    return 0;
}

int32_t java::net::DatagramSocket::getLocalPort()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getLocalPort()");
    return 0;
}

java::net::SocketAddress* java::net::DatagramSocket::getLocalSocketAddress()
{ /* stub */
    unimplemented_(u"java::net::SocketAddress* java::net::DatagramSocket::getLocalSocketAddress()");
    return 0;
}

int32_t java::net::DatagramSocket::getPort()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getPort()");
    return 0;
}

int32_t java::net::DatagramSocket::getReceiveBufferSize()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getReceiveBufferSize()");
    return 0;
}

java::net::SocketAddress* java::net::DatagramSocket::getRemoteSocketAddress()
{ /* stub */
    unimplemented_(u"java::net::SocketAddress* java::net::DatagramSocket::getRemoteSocketAddress()");
    return 0;
}

bool java::net::DatagramSocket::getReuseAddress()
{ /* stub */
    unimplemented_(u"bool java::net::DatagramSocket::getReuseAddress()");
    return 0;
}

int32_t java::net::DatagramSocket::getSendBufferSize()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getSendBufferSize()");
    return 0;
}

int32_t java::net::DatagramSocket::getSoTimeout()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getSoTimeout()");
    return 0;
}

int32_t java::net::DatagramSocket::getTrafficClass()
{ /* stub */
    unimplemented_(u"int32_t java::net::DatagramSocket::getTrafficClass()");
    return 0;
}

bool java::net::DatagramSocket::isBound()
{ /* stub */
    unimplemented_(u"bool java::net::DatagramSocket::isBound()");
    return 0;
}

bool java::net::DatagramSocket::isClosed()
{ /* stub */
    unimplemented_(u"bool java::net::DatagramSocket::isClosed()");
    return 0;
}

bool java::net::DatagramSocket::isConnected()
{ /* stub */
    unimplemented_(u"bool java::net::DatagramSocket::isConnected()");
    return 0;
}

void java::net::DatagramSocket::receive(DatagramPacket* arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::receive(DatagramPacket* arg0)");
}

void java::net::DatagramSocket::send(DatagramPacket* arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::send(DatagramPacket* arg0)");
}

void java::net::DatagramSocket::setBroadcast(bool arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setBroadcast(bool arg0)");
}

void java::net::DatagramSocket::setDatagramSocketImplFactory(DatagramSocketImplFactory* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::net::DatagramSocket::setDatagramSocketImplFactory(DatagramSocketImplFactory* arg0)");
}

void java::net::DatagramSocket::setReceiveBufferSize(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setReceiveBufferSize(int32_t arg0)");
}

void java::net::DatagramSocket::setReuseAddress(bool arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setReuseAddress(bool arg0)");
}

void java::net::DatagramSocket::setSendBufferSize(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setSendBufferSize(int32_t arg0)");
}

void java::net::DatagramSocket::setSoTimeout(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setSoTimeout(int32_t arg0)");
}

void java::net::DatagramSocket::setTrafficClass(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::net::DatagramSocket::setTrafficClass(int32_t arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::DatagramSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.DatagramSocket", 23);
    return c;
}

java::lang::Class* java::net::DatagramSocket::getClass0()
{
    return class_();
}

