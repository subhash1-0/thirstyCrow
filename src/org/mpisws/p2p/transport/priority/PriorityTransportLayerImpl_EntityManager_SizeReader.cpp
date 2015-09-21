// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_SizeReader.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/IntBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_BufferReader.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::PriorityTransportLayerImpl_EntityManager_SizeReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&)
    : super(PriorityTransportLayerImpl_EntityManager_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::PriorityTransportLayerImpl_EntityManager_SizeReader(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::org::mpisws::p2p::transport::P2PSocket* socket) 
    : PriorityTransportLayerImpl_EntityManager_SizeReader(PriorityTransportLayerImpl_EntityManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(socket);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::ctor(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    super::ctor(int32_t(4), socket);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::done(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    auto msgSize = npc(npc(buf)->asIntBuffer())->get();
    if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this))->append(u" reading message of size "_j)
            ->append(msgSize)->toString());

    if(msgSize > PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->MAX_MSG_SIZE) {
        if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(socket))->append(u" attempted to send a message of size "_j)
                ->append(msgSize)
                ->append(u". MAX_MSG_SIZE = "_j)
                ->append(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->MAX_MSG_SIZE)->toString());

        PriorityTransportLayerImpl_EntityManager_this->closeMe(socket);
        return;
    }
    new PriorityTransportLayerImpl_EntityManager_BufferReader(PriorityTransportLayerImpl_EntityManager_this, msgSize, socket);
}

java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::toString()
{
    return u"SizeReader"_j;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager.SizeReader", 85);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_SizeReader::getClass0()
{
    return class_();
}

