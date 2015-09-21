// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_handleValueRequest_4.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_incomingSocket_3.hpp>
#include <org/mpisws/p2p/transport/util/BufferReader.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
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

org::mpisws::p2p::transport::table::TableTransprotLayerImpl::TableTransprotLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::table::TableTransprotLayerImpl::TableTransprotLayerImpl(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::transport::util::Serializer* cSerializer, TableStore* tableStore, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env) 
    : TableTransprotLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(iSerializer,cSerializer,tableStore,tl,env);
}

constexpr int8_t org::mpisws::p2p::transport::table::TableTransprotLayerImpl::PASSTHROUGH;

constexpr int8_t org::mpisws::p2p::transport::table::TableTransprotLayerImpl::REQUEST;

constexpr int8_t org::mpisws::p2p::transport::table::TableTransprotLayerImpl::RESPONSE_SUCCESS;

constexpr int8_t org::mpisws::p2p::transport::table::TableTransprotLayerImpl::RESPONSE_FAILED;

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::ctor(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::transport::util::Serializer* cSerializer, TableStore* tableStore, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
{
    super::ctor();
    this->keySerializer = iSerializer;
    this->valueSerializer = cSerializer;
    this->knownValues = tableStore;
    this->tl = tl;
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
    this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(this->logger);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::requestValue(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"requestValue("_j)->append(static_cast< ::java::lang::Object* >(source))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(principal))
            ->append(u")"_j)->toString());

    if(npc(knownValues)->containsKey(principal)) {
        if(c != nullptr)
            npc(c)->receiveResult(java_cast< ::java::lang::Object* >(npc(knownValues)->get(principal)));

        return nullptr;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"requestValue("_j)->append(static_cast< ::java::lang::Object* >(source))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(principal))
            ->append(u") opening socket"_j)->toString());

    return npc(tl)->openSocket(source, new TableTransprotLayerImpl_requestValue_1(this, principal, c, source), options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new TableTransprotLayerImpl_openSocket_2(this, deliverSocketToMe, ret), options));
    return ret;
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* sock) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket() from "_j)->append(static_cast< ::java::lang::Object* >(sock))->toString());

    new ::org::mpisws::p2p::transport::util::BufferReader(sock, new TableTransprotLayerImpl_incomingSocket_3(this, sock), int32_t(1));
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::handleValueRequest(::org::mpisws::p2p::transport::P2PSocket* sock)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleValueRequest() from "_j)->append(static_cast< ::java::lang::Object* >(sock))->toString());

    new ::org::mpisws::p2p::transport::util::BufferReader(sock, new TableTransprotLayerImpl_handleValueRequest_4(this, sock));
}

bool org::mpisws::p2p::transport::table::TableTransprotLayerImpl::hasKey(::java::lang::Object* i)
{
    return npc(knownValues)->containsKey(i);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::destroy()
{
    npc(tl)->destroy();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.table.TableTransprotLayerImpl", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl::getClass0()
{
    return class_();
}

