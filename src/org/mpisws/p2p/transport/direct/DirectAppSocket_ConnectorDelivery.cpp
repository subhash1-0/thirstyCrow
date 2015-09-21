// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_ConnectorDelivery.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::DirectAppSocket_ConnectorDelivery(DirectAppSocket *DirectAppSocket_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_this(DirectAppSocket_this)
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::DirectAppSocket_ConnectorDelivery(DirectAppSocket *DirectAppSocket_this)
    : DirectAppSocket_ConnectorDelivery(DirectAppSocket_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::deliver()
{
    if(npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(DirectAppSocket_this->connector))) {
        npc(DirectAppSocket_this->connectorReceiver)->receiveResult(DirectAppSocket_this->connectorHandle, DirectAppSocket_this->connectorEndpoint);
    } else {
        npc(::java::lang::System::out())->println(u"NOT IMPLEMENTED: Connector died during application socket initiation."_j);
    }
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::getSeq()
{
    return -int32_t(1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectAppSocket.ConnectorDelivery", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_ConnectorDelivery::getClass0()
{
    return class_();
}

