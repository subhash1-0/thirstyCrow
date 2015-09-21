// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/ConnectorExceptionDelivery.java
#include <org/mpisws/p2p/transport/direct/ConnectorExceptionDelivery.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::ConnectorExceptionDelivery(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::ConnectorExceptionDelivery(::org::mpisws::p2p::transport::SocketCallback* connectorReceiver, ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle, ::java::io::IOException* e) 
    : ConnectorExceptionDelivery(*static_cast< ::default_init_tag* >(0))
{
    ctor(connectorReceiver,connectorHandle,e);
}

void org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::ctor(::org::mpisws::p2p::transport::SocketCallback* connectorReceiver, ::org::mpisws::p2p::transport::SocketRequestHandle* connectorHandle, ::java::io::IOException* e)
{
    super::ctor();
    this->e = e;
    this->connectorReceiver = connectorReceiver;
    this->connectorHandle = connectorHandle;
}

void org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::deliver()
{
    npc(connectorReceiver)->receiveException(connectorHandle, e);
}

int32_t org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::getSeq()
{
    return -int32_t(1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.ConnectorExceptionDelivery", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::ConnectorExceptionDelivery::getClass0()
{
    return class_();
}

