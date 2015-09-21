// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/LocalIdentifierStrategy.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::SimpleIdentityTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::SimpleIdentityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, Serializer* serializer, LocalIdentifierStrategy* localIdStrategy, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler)  /* throws(IOException) */
    : SimpleIdentityTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,serializer,localIdStrategy,env,handler);
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, Serializer* serializer, LocalIdentifierStrategy* localIdStrategy, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler) /* throws(IOException) */
{
    super::ctor();
    this->tl = tl;
    npc(java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(this->tl))->setCallback(this);
    this->errorHandler = handler;
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
    this->serializer = serializer;
    this->localIdStrategy = localIdStrategy;
    if(java_cast< LocalIdentifierStrategy* >(this->localIdStrategy) == nullptr) {
        this->localIdStrategy = new SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(this, java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier()));
    }
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new SimpleIdentityTransportLayer_openSocket_1(this, deliverSocketToMe, ret), options));
    return ret;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::destroy()
{
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(s);
    (new SimpleIdentityTransportLayer_incomingSocket_2(this, sib))->receiveSelectResult(s, true, false);
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.simpleidentity.SimpleIdentityTransportLayer", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer::getClass0()
{
    return class_();
}

