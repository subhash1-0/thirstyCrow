// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::init()
{
    sizeBytes = new ::int8_tArray(int32_t(4));
    sizeBuf = ::java::nio::ByteBuffer::wrap(sizeBytes);
    msgBuf = nullptr;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
    npc(socket)->close();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(sizeBuf)->hasRemaining()) {
        auto ret = npc(socket)->read(sizeBuf);
        if(ret == -int32_t(1)) {
            npc(socket)->close();
            return;
        }
        if(npc(sizeBuf)->hasRemaining()) {
            npc(socket)->register_(true, false, this);
            return;
        } else {
            auto size = ::rice::p2p::util::MathUtils::byteArrayToInt(sizeBytes);
            msgBuf = ::java::nio::ByteBuffer::allocate(size);
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Receiving BIG message of size:"_j)->append(size)
                    ->append(u" from:"_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))->toString());

            if(size > PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->MAX_BIG_MSG_SIZE) {
                if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Closing socket, BIG message of size:"_j)->append(size)
                        ->append(u" is too big! (max:"_j)
                        ->append(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->MAX_BIG_MSG_SIZE)
                        ->append(u") from:"_j)
                        ->append(static_cast< ::java::lang::Object* >(socket))->toString());

                npc(socket)->close();
                return;
            }
        }
    }
    if(npc(msgBuf)->hasRemaining()) {
        auto ret = npc(socket)->read(msgBuf);
        if(ret == -int32_t(1)) {
            npc(socket)->close();
            return;
        }
        if(npc(msgBuf)->hasRemaining()) {
            npc(socket)->register_(true, false, this);
            return;
        } else {
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received BIG message of size:"_j)->append(npc(msgBuf)->capacity())
                    ->append(u" from:"_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))->toString());

            npc(msgBuf)->flip();
            npc(sizeBuf)->clear();
            npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->callback)->messageReceived(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), msgBuf, npc(socket)->getOptions());
            msgBuf = nullptr;
            npc(socket)->register_(true, false, this);
            return;
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_handleBigMsgSocket_5::getClass0()
{
    return class_();
}

