// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerListener.hpp>
#include <org/mpisws/p2p/transport/util/DefaultCallback.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_sendMessage_2.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_VerifyHeaderReceiver.hpp>
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
org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::MagicNumberTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::MagicNumberTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::int8_tArray* header, int32_t timeOut) 
    : MagicNumberTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(wtl,env,errorHandler,header,timeOut);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::init()
{
    listeners = new ::java::util::ArrayList();
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::int8_tArray* header, int32_t timeOut)
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(MagicNumberTransportLayer::class_(), nullptr);
    this->environment = env;
    this->wire = wtl;
    this->HEADER = header;
    this->SOCKET_TIMEOUT = timeOut;
    this->errorHandler = errorHandler;
    this->callback = new ::org::mpisws::p2p::transport::util::DefaultCallback(logger);
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(wire)->setCallback(this);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    npc(wire)->setErrorHandler(handler);
    if(handler == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
        return;
    }
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::acceptMessages(bool b)
{
    npc(wire)->acceptMessages(b);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::acceptSockets(bool b)
{
    npc(wire)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(wire)->getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    auto const cancellable = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(cancellable)->setSubCancellable(npc(wire)->openSocket(i, new MagicNumberTransportLayer_openSocket_1(this, cancellable, deliverSocketToMe), options));
    return cancellable;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto msgWithHeader = new ::int8_tArray(npc(HEADER)->length + npc(m)->remaining());
    ::java::lang::System::arraycopy(HEADER, 0, msgWithHeader, 0, npc(HEADER)->length);
    npc(m)->get(msgWithHeader, npc(HEADER)->length, npc(m)->remaining());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    auto const cancellable = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    auto const buf = ::java::nio::ByteBuffer::wrap(msgWithHeader);
    npc(cancellable)->setSubCancellable(npc(wire)->sendMessage(i, buf, new MagicNumberTransportLayer_sendMessage_2(this, cancellable, deliverAckToMe, i, buf), options));
    return cancellable;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::destroy()
{
    npc(wire)->destroy();
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(s)->register_(true, false, new MagicNumberTransportLayer_VerifyHeaderReceiver(this, s));
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    if(npc(m)->remaining() < npc(HEADER)->length) {
        npc(errorHandler)->receivedUnexpectedData(i, npc(m)->array(), 0, nullptr);
        return;
    }
    auto hdr = new ::int8_tArray(npc(HEADER)->length);
    npc(m)->get(hdr);
    auto remaining = npc(m)->remaining();
    if(::java::util::Arrays::equals(HEADER, hdr)) {
        notifyListenersRead(npc(HEADER)->length, i, options, false, false);
        notifyListenersRead(remaining, i, options, true, false);
        npc(callback)->messageReceived(i, m, options);
        return;
    }
    notifyListenersRead(npc(HEADER)->length, i, options, false, false);
    notifyListenersRead(remaining, i, options, true, false);
    npc(errorHandler)->receivedUnexpectedData(i, npc(m)->array(), 0, nullptr);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_0(listeners);
        {
            npc(listeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_1(listeners);
        {
            npc(listeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::notifyListenersRead(int32_t bytesRead, ::java::lang::Object* identifier, ::java::util::Map* options, bool passthrough, bool socket)
{
    ::java::lang::Iterable* i;
    {
        synchronized synchronized_2(listeners);
        {
            i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(i)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::TransportLayerListener* l = java_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(_i->next());
        {
            npc(l)->read(bytesRead, identifier, options, passthrough, socket);
        }
    }
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::notifyListenersWrite(int32_t bytesRead, ::java::lang::Object* identifier, ::java::util::Map* options, bool passthrough, bool socket)
{
    ::java::lang::Iterable* i;
    {
        synchronized synchronized_3(listeners);
        {
            i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(i)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::TransportLayerListener* l = java_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(_i->next());
        {
            npc(l)->wrote(bytesRead, identifier, options, passthrough, socket);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.magicnumber.MagicNumberTransportLayer", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer::getClass0()
{
    return class_();
}

