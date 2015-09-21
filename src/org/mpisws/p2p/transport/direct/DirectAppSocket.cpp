// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_AcceptorDelivery.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::direct::DirectAppSocket::DirectAppSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectAppSocket::DirectAppSocket(::java::lang::Object* acceptor, ::java::lang::Object* connector, ::org::mpisws::p2p::transport::SocketCallback* connectorCallback, GenericNetworkSimulator* simulator, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::java::util::Map* options) 
    : DirectAppSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(acceptor,connector,connectorCallback,simulator,handle,options);
}

int8_tArray*& org::mpisws::p2p::transport::direct::DirectAppSocket::EOF_()
{
    clinit();
    return EOF__;
}
int8_tArray* org::mpisws::p2p::transport::direct::DirectAppSocket::EOF__;

constexpr int32_t org::mpisws::p2p::transport::direct::DirectAppSocket::MAX_BYTES_IN_FLIGHT;

void org::mpisws::p2p::transport::direct::DirectAppSocket::ctor(::java::lang::Object* acceptor, ::java::lang::Object* connector, ::org::mpisws::p2p::transport::SocketCallback* connectorCallback, GenericNetworkSimulator* simulator, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::java::util::Map* options)
{
    super::ctor();
    this->options = options;
    this->acceptor = acceptor;
    this->connector = connector;
    this->connectorReceiver = connectorCallback;
    this->simulator = simulator;
    this->connectorHandle = handle;
    auto aEnv = npc(simulator)->getEnvironment(acceptor);
    auto cEnv = npc(simulator)->getEnvironment(connector);
    acceptorLogger = npc(npc(aEnv)->getLogManager())->getLogger(DirectAppSocket::class_(), u""_j);
    connectorLogger = npc(npc(cEnv)->getLogManager())->getLogger(DirectAppSocket::class_(), u""_j);
    acceptorEndpoint = new DirectAppSocket_DirectAppSocketEndpoint(this, acceptor, acceptorLogger);
    connectorEndpoint = new DirectAppSocket_DirectAppSocketEndpoint(this, connector, connectorLogger);
    npc(acceptorEndpoint)->setCounterpart(connectorEndpoint);
    npc(connectorEndpoint)->setCounterpart(acceptorEndpoint);
}

org::mpisws::p2p::transport::direct::Delivery* org::mpisws::p2p::transport::direct::DirectAppSocket::getAcceptorDelivery()
{
    return new DirectAppSocket_AcceptorDelivery(this);
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket::toString()
{
    return ::java::lang::StringBuilder().append(u"DAS{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(connector)))
        ->append(u"["_j)
        ->append(static_cast< ::java::lang::Object* >(connectorReceiver))
        ->append(u"]->"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(acceptor)))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectAppSocket", 47);
    return c;
}

void org::mpisws::p2p::transport::direct::DirectAppSocket::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        EOF__ = new ::int8_tArray(int32_t(0));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket::getClass0()
{
    return class_();
}

