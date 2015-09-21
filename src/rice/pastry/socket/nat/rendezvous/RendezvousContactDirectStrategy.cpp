// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousContactDirectStrategy.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousContactDirectStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::RendezvousContactDirectStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::RendezvousContactDirectStrategy(RendezvousSocketNodeHandle* localNodeHandle, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy, ::rice::environment::Environment* environment) 
    : RendezvousContactDirectStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(localNodeHandle,addressStrategy,environment);
}

void rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::ctor(RendezvousSocketNodeHandle* localNodeHandle, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy, ::rice::environment::Environment* environment)
{
    super::ctor();
    this->localAddr = npc(localNodeHandle)->getAddress();
    this->environment = environment;
    this->addressStrategy = addressStrategy;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(RendezvousContactDirectStrategy::class_(), nullptr);
}

bool rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::canContactDirect(RendezvousSocketNodeHandle* remoteNode)
{
    if(npc(remoteNode)->canContactDirect())
        return true;

    auto a = npc(remoteNode)->getAddress();
    if(npc(a)->getNumAddresses() == 1) {
        return npc(npc(npc(a)->getInnermostAddress())->getAddress())->equals(static_cast< ::java::lang::Object* >(npc(npc(localAddr)->getInnermostAddress())->getAddress()));
    } else {
        auto ret = npc(npc(addressStrategy)->getAddress(localAddr, a))->equals(static_cast< ::java::lang::Object* >(npc(a)->getInnermostAddress()));
        if(ret && npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"rendezvous contacting direct:"_j)->append(static_cast< ::java::lang::Object* >(remoteNode))->toString());

        return ret;
    }
}

bool rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::canContactDirect(::java::lang::Object* remoteNode)
{ 
    return canContactDirect(dynamic_cast< RendezvousSocketNodeHandle* >(remoteNode));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousContactDirectStrategy", 65);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy::getClass0()
{
    return class_();
}

