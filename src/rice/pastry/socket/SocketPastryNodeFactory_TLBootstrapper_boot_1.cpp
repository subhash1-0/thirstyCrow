// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::SocketPastryNodeFactory_TLBootstrapper_boot_1(SocketPastryNodeFactory_TLBootstrapper *SocketPastryNodeFactory_TLBootstrapper_this, bool seed, ::java::util::Collection* bootaddresses)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_TLBootstrapper_this(SocketPastryNodeFactory_TLBootstrapper_this)
    , seed(seed)
    , bootaddresses(bootaddresses)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::init()
{
    done = false;
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::receiveResult(::java::util::Collection* initialSet)
{
    if(done)
        return;

    done = true;
    if(npc(SocketPastryNodeFactory_TLBootstrapper_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(SocketPastryNodeFactory_TLBootstrapper_this->logger)->log(::java::lang::StringBuilder().append(u"boot() beginning pns with "_j)->append(static_cast< ::java::lang::Object* >(initialSet))->toString());

    npc(npc(SocketPastryNodeFactory_TLBootstrapper_this->pn)->getLivenessProvider())->removeLivenessListener(java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(npc(SocketPastryNodeFactory_TLBootstrapper_this->listener)->get(0)));
    npc(SocketPastryNodeFactory_TLBootstrapper_this->pns)->getNearHandles(initialSet, new SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1(this, seed, bootaddresses));
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1::getClass0()
{
    return class_();
}

