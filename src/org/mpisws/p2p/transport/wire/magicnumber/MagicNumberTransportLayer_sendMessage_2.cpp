// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer_sendMessage_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2::MagicNumberTransportLayer_sendMessage_2(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* cancellable, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::lang::Object* i, ::java::nio::ByteBuffer* buf)
    : super(*static_cast< ::default_init_tag* >(0))
    , MagicNumberTransportLayer_this(MagicNumberTransportLayer_this)
    , cancellable(cancellable)
    , deliverAckToMe(deliverAckToMe)
    , i(i)
    , buf(buf)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
    if(npc(cancellable)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(cancellable)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != cancellable.getSubCancellable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(cancellable)->getSubCancellable()))->toString());

    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(cancellable);

    MagicNumberTransportLayer_this->notifyListenersWrite(npc(MagicNumberTransportLayer_this->HEADER)->length, i, npc(cancellable)->getOptions(), false, false);
    MagicNumberTransportLayer_this->notifyListenersWrite(npc(buf)->limit() - npc(MagicNumberTransportLayer_this->HEADER)->length, i, npc(cancellable)->getOptions(), true, false);
}

void org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex)
{
    if(npc(cancellable)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(msg) != npc(cancellable)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"msg != cancellable.getSubCancellable() (indicates a bug in the code) msg:"_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(cancellable)->getSubCancellable()))->toString());

    if(deliverAckToMe == nullptr) {
        npc(MagicNumberTransportLayer_this->errorHandler)->receivedException(i, ex);
    } else {
        npc(deliverAckToMe)->sendFailed(cancellable, ex);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2::getClass0()
{
    return class_();
}

