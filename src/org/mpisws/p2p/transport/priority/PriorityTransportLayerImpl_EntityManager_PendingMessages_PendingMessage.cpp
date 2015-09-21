// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_PendingMessages.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/MathUtils.hpp>

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

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage(PriorityTransportLayerImpl_EntityManager_PendingMessages *PriorityTransportLayerImpl_EntityManager_PendingMessages_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_PendingMessages_this(PriorityTransportLayerImpl_EntityManager_PendingMessages_this)
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage(PriorityTransportLayerImpl_EntityManager_PendingMessages *PriorityTransportLayerImpl_EntityManager_PendingMessages_this, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) 
    : PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage(PriorityTransportLayerImpl_EntityManager_PendingMessages_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(msg,deliverAckToMe,options);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::init()
{
    started = false;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::ctor(::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    super::ctor();
    init();
    this->msg = msg;
    this->deliverAckToMe = deliverAckToMe;
    this->options = options;
    this->sizeBuffer = ::java::nio::ByteBuffer::wrap(::rice::p2p::util::MathUtils::intToByteArray_(npc(msg)->remaining()));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::sendFailed(::java::lang::Exception* ex)
{
    if(deliverAckToMe != nullptr) {
        npc(deliverAckToMe)->sendFailed(this, ex);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::send() /* throws(IOException) */
{
    started = true;
    receiveSelectResult(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->socket, false, true);
}

java::lang::Object* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->i);
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::getMessage()
{
    return msg;
}

java::util::Map* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::cancel()
{
    if(!started) {
        npc(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->msgs)->remove(static_cast< ::java::lang::Object* >(this));
        return true;
    }
    return false;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    PriorityTransportLayerImpl_EntityManager_PendingMessages_this->receiveException(ioe);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(sizeBuffer)->hasRemaining()) {
        auto ret = npc(socket)->write(sizeBuffer);
        if(ret == -int32_t(1)) {
            npc(socket)->close();
            receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Remote node closed channel: "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString())));
            return;
        }
        if(npc(sizeBuffer)->hasRemaining()) {
            npc(socket)->register_(false, true, this);
            return;
        }
    }
    if(npc(msg)->hasRemaining()) {
        auto ret = npc(socket)->write(msg);
        if(ret == -int32_t(1)) {
            npc(socket)->close();
            receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Remote node closed channel: "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString())));
            return;
        }
        if(npc(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"BIG message wrote: "_j)->append(ret)
                ->append(u" of "_j)
                ->append(npc(msg)->capacity())->toString());

        if(npc(msg)->hasRemaining()) {
            npc(socket)->register_(false, true, this);
        } else {
            if(java_cast< PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage* >(npc(PriorityTransportLayerImpl_EntityManager_PendingMessages_this->msgs)->removeFirst()) != this)
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error, removing first was not this!"_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

            PriorityTransportLayerImpl_EntityManager_PendingMessages_this->sendNextMessage();
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager.PendingMessages.PendingMessage", 105);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage::getClass0()
{
    return class_();
}

