// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/nat/FirewallTLImpl.java
#include <org/mpisws/p2p/transport/nat/FirewallTLImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>

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

org::mpisws::p2p::transport::nat::FirewallTLImpl::FirewallTLImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::nat::FirewallTLImpl::FirewallTLImpl(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t udp_open_millis, ::rice::environment::Environment* env) 
    : FirewallTLImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,udp_open_millis,env);
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t udp_open_millis, ::rice::environment::Environment* env)
{
    super::ctor();
    this->UDP_OPEN_MILLIS = udp_open_millis;
    this->environment = env;
    this->timeSource = npc(environment)->getTimeSource();
    this->logger = npc(npc(env)->getLogManager())->getLogger(FirewallTLImpl::class_(), nullptr);
    this->udpTable = new ::java::util::HashMap();
    this->tl = tl;
    npc(tl)->setCallback(this);
    npc(tl)->acceptSockets(false);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::nat::FirewallTLImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto now = npc(timeSource)->currentTimeMillis();
    npc(udpTable)->put(i, ::java::lang::Long::valueOf(now));
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(udpTable)->containsKey(i)) {
        auto now = npc(timeSource)->currentTimeMillis();
        if((npc(java_cast< ::java::lang::Long* >(npc(udpTable)->get(i))))->longValue() + UDP_OPEN_MILLIS >= now) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"accepting messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(m))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(options))
                    ->append(u")"_j)->toString());

            npc(udpTable)->put(i, ::java::lang::Long::valueOf(now));
            npc(callback)->messageReceived(i, m, options);
            return;
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"dropping messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"closing incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    npc(s)->close();
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::acceptSockets(bool b)
{
    return;
}

java::lang::Object* org::mpisws::p2p::transport::nat::FirewallTLImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::nat::FirewallTLImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(tl)->openSocket(i, deliverSocketToMe, options);
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

void org::mpisws::p2p::transport::nat::FirewallTLImpl::destroy()
{
    npc(tl)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::nat::FirewallTLImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.nat.FirewallTLImpl", 43);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::nat::FirewallTLImpl::getClass0()
{
    return class_();
}

