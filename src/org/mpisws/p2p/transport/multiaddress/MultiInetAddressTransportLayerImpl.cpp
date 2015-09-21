// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_sendMessage_3.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.hpp>
#include <org/mpisws/p2p/transport/util/DefaultCallback.hpp>
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

org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::MultiInetAddressTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::MultiInetAddressTransportLayerImpl(MultiInetSocketAddress* localAddress, ::org::mpisws::p2p::transport::TransportLayer* wire, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler, AddressStrategy* strategy) 
    : MultiInetAddressTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(localAddress,wire,env,handler,strategy);
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::init()
{
    sendIdentifier = true;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::ctor(MultiInetSocketAddress* localAddress, ::org::mpisws::p2p::transport::TransportLayer* wire, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler, AddressStrategy* strategy)
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(MultiInetAddressTransportLayerImpl::class_(), nullptr);
    this->wire = wire;
    this->errorHandler = handler;
    this->localAddress = localAddress;
    this->strategy = strategy;
    MAX_NUM_ADDRESSES = npc(npc(env)->getParameters())->getInt(u"transport_epoch_max_num_addresses"_j);
    if(wire == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"TransportLayer<InetSocketAddress, ByteBuffer> wire must be non-null"_j);

    if(localAddress == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"EpochInetSocketAddress localAddress must be non-null"_j);

    this->callback = new ::org::mpisws::p2p::transport::util::DefaultCallback(env);
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    if(this->strategy == nullptr) {
        this->strategy = new SimpleAddressStrategy();
    }
    npc(wire)->setCallback(this);
}

org::mpisws::p2p::transport::multiaddress::AddressStrategy* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::getAddressStrategy()
{
    return strategy;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::openSocket(MultiInetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(npc(localAddress)->getSerializedLength());
    try {
        npc(localAddress)->serialize(sob);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(handle, ioe);
        return nullptr;
    }
    auto const b = sendIdentifier ? npc(sob)->getByteBuffer() : static_cast< ::java::nio::ByteBuffer* >(nullptr);
    auto addr = npc(strategy)->getAddress(getLocalIdentifier(), i);
    npc(handle)->setSubCancellable(npc(wire)->openSocket(addr, new MultiInetAddressTransportLayerImpl_openSocket_1(this, handle, i, b, deliverSocketToMe), options));
    return handle;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< MultiInetSocketAddress* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u"):"_j)
            ->append(sendIdentifier)->toString());

    if(sendIdentifier) {
        auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(s, int32_t(1024));
        npc(s)->register_(true, false, new MultiInetAddressTransportLayerImpl_incomingSocket_2(this, sib));
    } else {
        npc(callback)->incomingSocket(new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(new MultiInetSocketAddress(java_cast< ::java::net::InetSocketAddress* >(npc(s)->getIdentifier())), s, logger, errorHandler, npc(s)->getOptions()));
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::sendMessage(MultiInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    auto const handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    ::java::nio::ByteBuffer* buf;
    if(sendIdentifier) {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(npc(m)->remaining() + npc(localAddress)->getSerializedLength());
        try {
            npc(localAddress)->serialize(sob);
            npc(sob)->write(npc(m)->array(), npc(m)->position(), npc(m)->remaining());
        } catch (::java::io::IOException* ioe) {
            if(deliverAckToMe == nullptr) {
                npc(errorHandler)->receivedException(i, ioe);
            } else {
                npc(deliverAckToMe)->sendFailed(handle, ioe);
            }
            return handle;
        }
        buf = ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes());
    } else {
        buf = m;
    }
    npc(handle)->setSubCancellable(npc(wire)->sendMessage(npc(strategy)->getAddress(getLocalIdentifier(), i), buf, new MultiInetAddressTransportLayerImpl_sendMessage_3(this, handle, deliverAckToMe, i), options));
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< MultiInetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

java::lang::String* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"MultiInetAddrTL{"_j)->append(static_cast< ::java::lang::Object* >(localAddress))
        ->append(u"}"_j)->toString();
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    if(sendIdentifier) {
        auto pos = npc(m)->position();
        auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(m)->array(), pos);
        MultiInetSocketAddress* eisa;
        try {
            eisa = MultiInetSocketAddress::build(sib);
        } catch (::java::io::IOException* ioe) {
            npc(errorHandler)->receivedUnexpectedData(new MultiInetSocketAddress(i), npc(m)->array(), pos, nullptr);
            return;
        }
        npc(m)->position(npc(npc(m)->array())->length - npc(sib)->bytesRemaining());
        npc(callback)->messageReceived(eisa, m, options);
    } else {
        npc(callback)->messageReceived(new MultiInetSocketAddress(i), m, options);
    }
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::net::InetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::getLocalIdentifier()
{
    return localAddress;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::acceptMessages(bool b)
{
    npc(wire)->acceptMessages(b);
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::acceptSockets(bool b)
{
    npc(wire)->acceptSockets(b);
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::destroy()
{
    npc(wire)->destroy();
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::setSendIdentifier(bool sendIdentifier)
{
    this->sendIdentifier = sendIdentifier;
}

bool org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::isSendIdentifier()
{
    return sendIdentifier;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.multiaddress.MultiInetAddressTransportLayerImpl", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl::getClass0()
{
    return class_();
}

