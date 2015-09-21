// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_sendMessage_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_sendMessage_2::LivenessTransportLayerImpl_sendMessage_2(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::lang::Object* i)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
    , handle(handle)
    , deliverAckToMe(deliverAckToMe)
    , i(i)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_sendMessage_2::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != handle.getSubCancelable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(handle);

}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_sendMessage_2::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != handle.getSubCancelable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    if(deliverAckToMe == nullptr) {
        npc(LivenessTransportLayerImpl_this->errorHandler)->receivedException(i, ex);
    } else {
        npc(deliverAckToMe)->sendFailed(handle, ex);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_sendMessage_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_sendMessage_2::getClass0()
{
    return class_();
}

