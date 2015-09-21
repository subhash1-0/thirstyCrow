// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl_sendMessage_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/priority/QueueOverflowException.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2::CommonAPITransportLayerImpl_sendMessage_2(CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this, ::rice::p2p::commonapi::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommonAPITransportLayerImpl_this(CommonAPITransportLayerImpl_this)
    , i(i)
    , m(m)
    , handle(handle)
    , deliverAckToMe(deliverAckToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(npc(CommonAPITransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(CommonAPITransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u").ack()"_j)->toString());

    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != cancellable.getSubCancellable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(handle);

}

void org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex)
{
    if(dynamic_cast< ::org::mpisws::p2p::transport::exception::NodeIsFaultyException* >(ex) != nullptr) {
        ex = new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m, ex);
    }
    if(dynamic_cast< ::org::mpisws::p2p::transport::priority::QueueOverflowException* >(ex) != nullptr) {
        ex = new ::org::mpisws::p2p::transport::priority::QueueOverflowException(i, m, ex);
    }
    if(npc(CommonAPITransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(CommonAPITransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"sendFailed("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString(), ex);

    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != cancellable.getSubCancellable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(deliverAckToMe == nullptr) {
        npc(CommonAPITransportLayerImpl_this->errorHandler)->receivedException(i, ex);
    } else {
        npc(deliverAckToMe)->sendFailed(handle, ex);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2::getClass0()
{
    return class_();
}

