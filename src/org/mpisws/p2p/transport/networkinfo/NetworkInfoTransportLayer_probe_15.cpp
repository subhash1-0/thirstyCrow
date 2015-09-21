// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_probe_15.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_probe_15::NetworkInfoTransportLayer_probe_15(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::java::net::InetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResponseToMe, ::java::util::Map* options, ::boolArray* success)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , addr(addr)
    , uid(uid)
    , deliverResponseToMe(deliverResponseToMe)
    , options(options)
    , success(success)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_probe_15::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    if(npc(NetworkInfoTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(NetworkInfoTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(u"probe("_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResponseToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").receiveResult("_j)
            ->append(static_cast< ::java::lang::Object* >(sock))
            ->append(u")"_j)->toString());

    (*success)[int32_t(1)] = true;
    if((*success)[int32_t(0)]) {
        npc(deliverResponseToMe)->receiveResult(::java::lang::Long::valueOf(uid));
    }
    npc(sock)->close();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_probe_15::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(npc(NetworkInfoTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(NetworkInfoTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(u"probe("_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResponseToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u").tcpFailure2() "_j)
            ->append(static_cast< ::java::lang::Object* >(ex))->toString());

    if(deliverResponseToMe != nullptr)
        npc(deliverResponseToMe)->receiveException(ex);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_probe_15::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_probe_15::getClass0()
{
    return class_();
}

