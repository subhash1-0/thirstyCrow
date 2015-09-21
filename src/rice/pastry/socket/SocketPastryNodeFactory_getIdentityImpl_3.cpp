// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getIdentityImpl_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

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

rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_3::SocketPastryNodeFactory_getIdentityImpl_3(SocketPastryNodeFactory *SocketPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_3::canChange(TransportLayerNodeHandle* oldDest, TransportLayerNodeHandle* newDest)
{
    if(npc(java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(newDest)->getAddress()))->equals(static_cast< ::java::lang::Object* >(java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(oldDest)->getAddress())))) {
        if(npc(SocketPastryNodeFactory_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(SocketPastryNodeFactory_this->logger)->log(::java::lang::StringBuilder().append(u"canChange("_j)->append(static_cast< ::java::lang::Object* >(oldDest))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(newDest))
                ->append(u")"_j)->toString());

        if(npc(newDest)->getEpoch() > npc(oldDest)->getEpoch()) {
            if(npc(SocketPastryNodeFactory_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(SocketPastryNodeFactory_this->logger)->log(::java::lang::StringBuilder().append(u"canChange("_j)->append(static_cast< ::java::lang::Object* >(oldDest))
                    ->append(u":"_j)
                    ->append(npc(oldDest)->getEpoch())
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(newDest))
                    ->append(u":"_j)
                    ->append(npc(newDest)->getEpoch())
                    ->append(u"):true"_j)->toString());

            return true;
        }
    } else {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"canChange("_j)->append(static_cast< ::java::lang::Object* >(oldDest))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(newDest))
            ->append(u") doesn't make any sense, these aren't comparable to eachother."_j)->toString());
    }
    if(npc(SocketPastryNodeFactory_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(SocketPastryNodeFactory_this->logger)->log(::java::lang::StringBuilder().append(u"canChange("_j)->append(static_cast< ::java::lang::Object* >(oldDest))
            ->append(u":"_j)
            ->append(npc(oldDest)->getEpoch())
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(newDest))
            ->append(u":"_j)
            ->append(npc(newDest)->getEpoch())
            ->append(u"):false"_j)->toString());

    return false;
}

bool rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_3::canChange(::java::lang::Object* oldDest, ::java::lang::Object* newDest)
{ 
    return canChange(dynamic_cast< TransportLayerNodeHandle* >(oldDest), dynamic_cast< TransportLayerNodeHandle* >(newDest));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIdentityImpl_3::getClass0()
{
    return class_();
}

