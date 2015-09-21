// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl_sendMessage_2.hpp>
#include <org/mpisws/p2p/transport/commonapi/IdFactory.hpp>
#include <org/mpisws/p2p/transport/commonapi/OptionsAdder.hpp>
#include <org/mpisws/p2p/transport/commonapi/RawMessageDeserializer.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/util/DefaultCallback.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

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

org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::CommonAPITransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::CommonAPITransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, IdFactory* idFactory, RawMessageDeserializer* deserializer, OptionsAdder* optionsAdder, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env) 
    : CommonAPITransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,idFactory,deserializer,optionsAdder,errorHandler,env);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::init()
{
    destroyed = false;
}

java::lang::String*& org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS()
{
    clinit();
    return MSG_CLASS_;
}
java::lang::String* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS_;

java::lang::String*& org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING()
{
    clinit();
    return MSG_STRING_;
}
java::lang::String* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING_;

java::lang::String*& org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE()
{
    clinit();
    return MSG_TYPE_;
}
java::lang::String* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE_;

java::lang::String*& org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR()
{
    clinit();
    return MSG_ADDR_;
}
java::lang::String* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR_;

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, IdFactory* idFactory, RawMessageDeserializer* deserializer, OptionsAdder* optionsAdder, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(CommonAPITransportLayerImpl::class_(), nullptr);
    this->tl = tl;
    this->deserializer = deserializer;
    this->optionsAdder = optionsAdder;
    if(this->optionsAdder == nullptr) {
        this->optionsAdder = new CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1(this);
    }
    if(tl == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"tl must be non-null"_j);

    if(idFactory == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"idFactroy must be non-null"_j);

    if(deserializer == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deserializer must be non-null"_j);

    this->idFactory = idFactory;
    this->errorHandler = errorHandler;
    if(java_cast< ::org::mpisws::p2p::transport::TransportLayerCallback* >(this->callback) == nullptr) {
        this->callback = new ::org::mpisws::p2p::transport::util::DefaultCallback(env);
    }
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(tl)->setCallback(this);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

rice::p2p::commonapi::NodeHandle* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::sendMessage(::rice::p2p::commonapi::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(destroyed)
        return nullptr;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());

    auto const handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    ::java::nio::ByteBuffer* buf;
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(deserializer)->serialize(m, sob);
    } catch (::java::io::IOException* ioe) {
        if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(ioe) != nullptr) {
            ioe = new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m, ioe);
        }
        if(deliverAckToMe == nullptr) {
            npc(errorHandler)->receivedException(i, ioe);
        } else {
            npc(deliverAckToMe)->sendFailed(handle, ioe);
        }
        return handle;
    }
    buf = ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u") serizlized:"_j)
            ->append(static_cast< ::java::lang::Object* >(buf))->toString());

    npc(handle)->setSubCancellable(npc(tl)->sendMessage(i, buf, new CommonAPITransportLayerImpl_sendMessage_2(this, i, m, handle, deliverAckToMe), npc(optionsAdder)->addOptions(options, m)));
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(i), dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::messageReceived(::rice::p2p::commonapi::NodeHandle* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    auto buf = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(m)->array(), npc(m)->position());
    auto ret = npc(deserializer)->deserialize(buf, i);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(ret))
            ->append(u")"_j)->toString());

    npc(callback)->messageReceived(i, ret, options);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::destroy()
{
    destroyed = true;
    npc(tl)->destroy();
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::openSocket(::rice::p2p::commonapi::NodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    return npc(tl)->openSocket(i, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    npc(callback)->incomingSocket(s);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.commonapi.CommonAPITransportLayerImpl", 62);
    return c;
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::clinit()
{
struct string_init_ {
    string_init_() {
    MSG_CLASS_ = u"commonapi_msg_class"_j;
    MSG_STRING_ = u"commonapi_msg_string"_j;
    MSG_TYPE_ = u"commonapi_msg_type"_j;
    MSG_ADDR_ = u"commonapi_msg_addr"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::getClass0()
{
    return class_();
}

