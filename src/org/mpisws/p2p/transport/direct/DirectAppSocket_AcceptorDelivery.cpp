// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_AcceptorDelivery.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/SocketTimeoutException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/direct/ConnectorExceptionDelivery.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_ConnectorDelivery.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>

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

org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::DirectAppSocket_AcceptorDelivery(DirectAppSocket *DirectAppSocket_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_this(DirectAppSocket_this)
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::DirectAppSocket_AcceptorDelivery(DirectAppSocket *DirectAppSocket_this)
    : DirectAppSocket_AcceptorDelivery(DirectAppSocket_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::deliver()
{
    if(npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(DirectAppSocket_this->acceptor))) {
        auto acceptorTL = npc(DirectAppSocket_this->simulator)->getTL(java_cast< ::java::lang::Object* >(DirectAppSocket_this->acceptor));
        if(npc(acceptorTL)->canReceiveSocket()) {
            npc(acceptorTL)->finishReceiveSocket(DirectAppSocket_this->acceptorEndpoint);
            npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_ConnectorDelivery(DirectAppSocket_this), static_cast< int32_t >(::java::lang::Math::round(npc(DirectAppSocket_this->simulator)->networkDelay(java_cast< ::java::lang::Object* >(DirectAppSocket_this->acceptor), java_cast< ::java::lang::Object* >(DirectAppSocket_this->connector)))));
        } else {
            npc(DirectAppSocket_this->simulator)->enqueueDelivery(new ConnectorExceptionDelivery(DirectAppSocket_this->connectorReceiver, DirectAppSocket_this->connectorHandle, new ::java::net::SocketTimeoutException()), static_cast< int32_t >(::java::lang::Math::round(npc(DirectAppSocket_this->simulator)->networkDelay(java_cast< ::java::lang::Object* >(DirectAppSocket_this->acceptor), java_cast< ::java::lang::Object* >(DirectAppSocket_this->connector)))));
        }
    } else {
        npc(DirectAppSocket_this->simulator)->enqueueDelivery(new ConnectorExceptionDelivery(DirectAppSocket_this->connectorReceiver, DirectAppSocket_this->connectorHandle, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(DirectAppSocket_this->acceptor))), 0);
    }
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::getSeq()
{
    return -int32_t(1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectAppSocket.AcceptorDelivery", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_AcceptorDelivery::getClass0()
{
    return class_();
}

