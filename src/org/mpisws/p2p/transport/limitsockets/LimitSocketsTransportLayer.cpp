// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedHashMap.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>

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
org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::LimitSocketsTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::LimitSocketsTransportLayer(int32_t max_sockets, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::rice::environment::Environment* env) 
    : LimitSocketsTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(max_sockets,tl,handler,env);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::ctor(int32_t max_sockets, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::rice::environment::Environment* env)
{
    super::ctor();
    this->MAX_SOCKETS = max_sockets;
    this->tl = tl;
    this->logger = npc(npc(env)->getLogManager())->getLogger(LimitSocketsTransportLayer::class_(), nullptr);
    this->timer = npc(npc(env)->getSelectorManager())->getTimer();
    this->cache = new ::java::util::LinkedHashMap(MAX_SOCKETS, 0.75f, true);
    this->handler = handler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->handler) == nullptr) {
        this->handler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(tl)->setCallback(this);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".openSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* const ret = new LimitSocketsTransportLayer_openSocket_1(this, i, deliverSocketToMe, options, i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new LimitSocketsTransportLayer_openSocket_2(this, i, deliverSocketToMe, ret, options), options));
    return ret;
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".incomingSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    npc(callback)->incomingSocket(getLSSock(s));
}

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::getLSSock(::org::mpisws::p2p::transport::P2PSocket* sock)
{
    auto ret = new LimitSocketsTransportLayer_LSSocket(this, sock);
    npc(cache)->put(static_cast< ::java::lang::Object* >(ret), static_cast< ::java::lang::Object* >(ret));
    closeIfNecessary();
    return ret;
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::closeIfNecessary()
{
    ::java::util::Collection* closeMe = new ::java::util::ArrayList();
    {
        synchronized synchronized_0(cache);
        {
            while (npc(cache)->size() > MAX_SOCKETS) {
                auto i = npc(npc(cache)->keySet())->iterator();
                npc(closeMe)->add(java_cast< LimitSocketsTransportLayer_LSSocket* >(npc(i)->next()));
                npc(i)->remove();
            }
        }
    }
    for (auto _i = npc(closeMe)->iterator(); _i->hasNext(); ) {
        LimitSocketsTransportLayer_LSSocket* sock = java_cast< LimitSocketsTransportLayer_LSSocket* >(_i->next());
        {
            npc(sock)->forceClose();
        }
    }
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::touch(LimitSocketsTransportLayer_LSSocket* socket)
{
    {
        synchronized synchronized_1(cache);
        {
            if(java_cast< LimitSocketsTransportLayer_LSSocket* >(npc(cache)->get(static_cast< ::java::lang::Object* >(socket))) == nullptr) {
                npc(cache)->put(static_cast< ::java::lang::Object* >(socket), static_cast< ::java::lang::Object* >(socket));
                closeIfNecessary();
            }
        }
    }
}

java::lang::String* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::toString()
{
    return ::java::lang::StringBuilder().append(u"LimitSocks<"_j)->append(npc(cache)->size())
        ->append(u">"_j)->toString();
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->handler = handler;
    npc(tl)->setErrorHandler(handler);
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::destroy()
{
    npc(tl)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.limitsockets.LimitSocketsTransportLayer", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer::getClass0()
{
    return class_();
}

