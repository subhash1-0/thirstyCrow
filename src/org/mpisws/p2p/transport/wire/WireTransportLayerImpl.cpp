// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/WireTransportLayerImpl.java
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketCountListener.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerListener.hpp>
#include <org/mpisws/p2p/transport/util/DefaultCallback.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/wire/BogusUDPLayerImpl.hpp>
#include <org/mpisws/p2p/transport/wire/TCPLayer.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayer.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::wire::WireTransportLayerImpl::WireTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::WireTransportLayerImpl::WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)  /* throws(IOException) */
    : WireTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindAddress,env,errorHandler);
}

org::mpisws::p2p::transport::wire::WireTransportLayerImpl::WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableServer)  /* throws(IOException) */
    : WireTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindAddress,env,errorHandler,enableServer);
}

org::mpisws::p2p::transport::wire::WireTransportLayerImpl::WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableTCPServer, bool enableUDPServer)  /* throws(IOException) */
    : WireTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindAddress,env,errorHandler,enableTCPServer,enableUDPServer);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::init()
{
    forceBindAddress = false;
    destroyed = false;
    listeners = new ::java::util::ArrayList();
    slisteners = new ::java::util::ArrayList();
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(IOException) */
{
    ctor(bindAddress, env, errorHandler, true);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableServer) /* throws(IOException) */
{
    ctor(bindAddress, env, errorHandler, enableServer, enableServer);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableTCPServer, bool enableUDPServer) /* throws(IOException) */
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(WireTransportLayer::class_(), nullptr);
    this->bindAddress = bindAddress;
    this->environment = env;
    auto p = npc(this->environment)->getParameters();
    if(npc(p)->contains(u"wire_forceBindAddress"_j)) {
        forceBindAddress = npc(p)->getBoolean(u"wire_forceBindAddress"_j);
    }
    this->callback = new ::org::mpisws::p2p::transport::util::DefaultCallback(logger);
    this->errorHandler = errorHandler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    if(enableUDPServer) {
        udp = new UDPLayerImpl(this);
    } else {
        udp = new BogusUDPLayerImpl();
    }
    try {
        tcp = new TCPLayer(this, enableTCPServer);
    } catch (::java::io::IOException* ioe) {
        npc(udp)->destroy();
        throw ioe;
    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::openSocket(::java::net::InetSocketAddress* destination, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(tcp)->openSocket(destination, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(destination))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    return npc(udp)->sendMessage(destination, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::getLocalIdentifier()
{
    return bindAddress;
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"destroy()"_j);

    destroyed = true;
    npc(udp)->destroy();
    npc(tcp)->destroy();
}

bool org::mpisws::p2p::transport::wire::WireTransportLayerImpl::isDestroyed()
{
    return destroyed;
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    if(handler == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
        return;
    }
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::acceptMessages(bool b)
{
    npc(udp)->acceptMessages(b);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::acceptSockets(bool b)
{
    npc(tcp)->acceptSockets(b);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::messageReceived(::java::net::InetSocketAddress* address, ::java::nio::ByteBuffer* buffer, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(address, buffer, options);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* sm) /* throws(IOException) */
{
    broadcastChannelOpened(java_cast< ::java::net::InetSocketAddress* >(npc(sm)->getIdentifier()), npc(sm)->getOptions(), false);
    npc(callback)->incomingSocket(sm);
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_0(listeners);
        {
            npc(listeners)->add(listener);
        }
    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_1(listeners);
        {
            npc(listeners)->remove(listener);
        }
    }
}

java::lang::Iterable* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::getTLlisteners()
{
    {
        synchronized synchronized_2(listeners);
        {
            return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::addSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener)
{
    {
        synchronized synchronized_3(slisteners);
        {
            npc(slisteners)->add(listener);
        }
    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::removeSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener)
{
    {
        synchronized synchronized_4(slisteners);
        {
            npc(slisteners)->remove(listener);
        }
    }
}

java::lang::Iterable* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::getSlisteners()
{
    {
        synchronized synchronized_5(slisteners);
        {
            return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(slisteners));
        }
    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::broadcastChannelOpened(::java::net::InetSocketAddress* addr, ::java::util::Map* options, bool outgoing)
{
    for (auto _i = npc(getSlisteners())->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::SocketCountListener* listener = java_cast< ::org::mpisws::p2p::transport::SocketCountListener* >(_i->next());
        
                        npc(listener)->socketOpened(addr, options, outgoing);

    }
}

void org::mpisws::p2p::transport::wire::WireTransportLayerImpl::broadcastChannelClosed(::java::net::InetSocketAddress* addr, ::java::util::Map* options)
{
    for (auto _i = npc(getSlisteners())->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::SocketCountListener* listener = java_cast< ::org::mpisws::p2p::transport::SocketCountListener* >(_i->next());
        
                        npc(listener)->socketClosed(addr, options);

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.WireTransportLayerImpl", 52);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::WireTransportLayerImpl::getClass0()
{
    return class_();
}

