// Generated from /pastry-2.1/src/rice/pastry/socket/nat/StubNATHandler.java
#include <rice/pastry/socket/nat/StubNATHandler.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/String.hpp>

rice::pastry::socket::nat::StubNATHandler::StubNATHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::StubNATHandler::StubNATHandler(::rice::environment::Environment* environment, ::java::net::InetAddress* address) 
    : StubNATHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(environment,address);
}

void rice::pastry::socket::nat::StubNATHandler::init()
{
    errorString = u"Stub NATHandler implementation.  Plese refer to http://freepastry.org/FreePastry/nat.html to better configure FreePastry for your environment."_j;
}

void rice::pastry::socket::nat::StubNATHandler::ctor(::rice::environment::Environment* environment, ::java::net::InetAddress* address)
{
    super::ctor();
    init();
}

java::net::InetAddress* rice::pastry::socket::nat::StubNATHandler::getFireWallExternalAddress()
{
    return nullptr;
}

java::net::InetAddress* rice::pastry::socket::nat::StubNATHandler::findFireWall(::java::net::InetAddress* bindAddress) /* throws(IOException) */
{
    throw new ::java::io::IOException(errorString);
}

int32_t rice::pastry::socket::nat::StubNATHandler::findAvailableFireWallPort(int32_t internal, int32_t external, int32_t tries, ::java::lang::String* appName) /* throws(IOException) */
{
    throw new ::java::io::IOException(errorString);
}

void rice::pastry::socket::nat::StubNATHandler::openFireWallPort(int32_t local, int32_t external, ::java::lang::String* appName) /* throws(IOException) */
{
    throw new ::java::io::IOException(errorString);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::StubNATHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.StubNATHandler", 37);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::StubNATHandler::getClass0()
{
    return class_();
}

