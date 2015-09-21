// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/sourceroute/DefaultForwardSourceRouteStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTap.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_sendMessage_3.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::SourceRouteTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::SourceRouteTransportLayerImpl(SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* etl, SourceRouteForwardStrategy* fSRs, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) 
    : SourceRouteTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(srFactory,etl,fSRs,env,errorHandler);
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::ctor(SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* etl, SourceRouteForwardStrategy* fSRs, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler)
{
    super::ctor();
    this->etl = etl;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(SourceRouteTransportLayerImpl::class_(), nullptr);
    this->srFactory = srFactory;
    this->errorHandler = errorHandler;
    localIdentifier = npc(java_cast< SourceRouteFactory* >(this->srFactory))->getSourceRoute(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier())));
    taps = new ::java::util::ArrayList();
    MAX_NUM_HOPS = npc(npc(env)->getParameters())->getInt(u"transport_sr_max_num_hops"_j);
    this->forwardSourceRouteStrategy = fSRs;
    if(java_cast< SourceRouteForwardStrategy* >(this->forwardSourceRouteStrategy) == nullptr) {
        this->forwardSourceRouteStrategy = new DefaultForwardSourceRouteStrategy();
    }
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(etl)->setCallback(this);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::openSocket(SourceRoute* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(npc(i)->getNumHops() <= 1) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"SourceRoute must have more than 1 hop! sr:"_j)->append(static_cast< ::java::lang::Object* >(i))->toString());
    }
    if(!npc(java_cast< ::java::lang::Object* >(npc(i)->getFirstHop()))->equals(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()))) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"SourceRoute must start with self! sr:"_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" self:"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier())))->toString());
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(npc(i)->getSerializedLength());
    try {
        npc(i)->serialize(sob);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(handle, ioe);
        return handle;
    }
    auto const b = ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes());
    npc(handle)->setSubCancellable(npc(etl)->openSocket(java_cast< ::java::lang::Object* >(npc(i)->getHop(int32_t(1))), new SourceRouteTransportLayerImpl_openSocket_1(this, handle, i, b, deliverSocketToMe), options));
    return handle;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< SourceRoute* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::openSocketHelper(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::org::mpisws::p2p::transport::P2PSocket* socket, SourceRoute* i)
{
    npc(deliverSocketToMe)->receiveResult(handle, new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(i, socket, logger, errorHandler, npc(socket)->getOptions()));
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::incomingSocketHelper(::org::mpisws::p2p::transport::P2PSocket* socket, SourceRoute* sr) /* throws(IOException) */
{
    npc(callback)->incomingSocket(new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(sr, socket, logger, errorHandler, npc(socket)->getOptions()));
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* socka) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socka))
            ->append(u")"_j)->toString());

    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socka, int32_t(1024));
    npc(socka)->register_(true, false, new SourceRouteTransportLayerImpl_incomingSocket_2(this, sib, socka));
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::sendMessage(SourceRoute* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    if(npc(i)->getNumHops() <= 1) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"SourceRoute must have more than 1 hop! sr:"_j)->append(static_cast< ::java::lang::Object* >(i))->toString());
    }
    if(!npc(java_cast< ::java::lang::Object* >(npc(i)->getFirstHop()))->equals(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()))) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"SourceRoute must start with self! sr:"_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" self:"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier())))->toString());
    }
    ::java::nio::ByteBuffer* buf;
    auto const handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(npc(m)->remaining() + npc(i)->getSerializedLength());
    try {
        npc(i)->serialize(sob);
        npc(sob)->write(npc(m)->array(), npc(m)->position(), npc(m)->remaining());
    } catch (::java::io::IOException* ioe) {
        if(deliverAckToMe == nullptr) {
            npc(errorHandler)->receivedException(i, ioe);
        } else {
            npc(deliverAckToMe)->sendFailed(handle, ioe);
        }
        return nullptr;
    }
    buf = ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes());
    npc(handle)->setSubCancellable(npc(etl)->sendMessage(java_cast< ::java::lang::Object* >(npc(i)->getHop(int32_t(1))), buf, new SourceRouteTransportLayerImpl_sendMessage_3(this, handle, deliverAckToMe, i), options));
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< SourceRoute* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(!npc(m)->hasRemaining()) {
        npc(errorHandler)->receivedUnexpectedData(npc(srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()), i), npc(m)->array(), npc(m)->position(), nullptr);
    }
    auto pos = npc(m)->position();
    auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(m)->array(), pos);
    SourceRoute* tempSr;
    try {
        tempSr = npc(srFactory)->build(sib, java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()), i);
    } catch (::java::lang::Exception* e) {
        npc(errorHandler)->receivedException(npc(srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()), i), e);
        return;
    }
    auto const sr = tempSr;
    npc(m)->position(npc(npc(m)->array())->length - npc(sib)->bytesRemaining());
    if(npc(java_cast< ::java::lang::Object* >(npc(sr)->getLastHop()))->equals(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier()))) {
        npc(callback)->messageReceived(npc(srFactory)->reverse(sr), m, options);
    } else {
        auto hopNum = npc(sr)->getHop(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(etl)->getLocalIdentifier())));
        if(hopNum < 1) {
            npc(errorHandler)->receivedUnexpectedData(sr, npc(m)->array(), pos, nullptr);
            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"I'm hop "_j)->append(hopNum)
                ->append(u" in "_j)
                ->append(static_cast< ::java::lang::Object* >(sr))->toString());

        for (auto _i = npc(taps)->iterator(); _i->hasNext(); ) {
            SourceRouteTap* tap = java_cast< SourceRouteTap* >(_i->next());
            {
                auto retArr = new ::int8_tArray(npc(npc(m)->array())->length);
                ::java::lang::System::arraycopy(npc(m)->array(), 0, retArr, 0, npc(retArr)->length);
                auto ret = ::java::nio::ByteBuffer::wrap(retArr);
                npc(ret)->position(npc(m)->position());
                npc(tap)->receivedMessage(ret, sr);
            }
        }
        npc(m)->position(pos);
        npc(etl)->sendMessage(java_cast< ::java::lang::Object* >(npc(sr)->getHop(hopNum + int32_t(1))), m, nullptr, nullptr);
    }
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* errorHandler)
{
    this->errorHandler = errorHandler;
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::acceptMessages(bool b)
{
    npc(etl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::acceptSockets(bool b)
{
    npc(etl)->acceptSockets(b);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::getLocalIdentifier()
{
    return localIdentifier;
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::destroy()
{
    npc(etl)->destroy();
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::addSourceRouteTap(SourceRouteTap* tap)
{
    npc(taps)->add(tap);
}

bool org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::removeSourceRouteTap(SourceRouteTap* tap)
{
    return npc(taps)->remove(tap);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.SourceRouteTransportLayerImpl", 66);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl::getClass0()
{
    return class_();
}

