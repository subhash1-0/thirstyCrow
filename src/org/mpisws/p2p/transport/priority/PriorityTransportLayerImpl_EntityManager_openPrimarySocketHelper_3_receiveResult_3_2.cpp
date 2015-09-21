// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
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

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3 *PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this, ::java::lang::Object* i, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this)
    , i(i)
    , handle(handle)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::init()
{
    writeMe = ::java::nio::ByteBuffer::wrap(PriorityTransportLayerImpl::PRIMARY_SOCKET());
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead || !canWrite)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"expected to write!  canRead:"_j)->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)->toString());

    if(npc(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opened Primary socket "_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(i))->toString());

    if(npc(socket)->write(writeMe) == -int32_t(1)) {
        PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->cancelLivenessChecker(i);
        npc(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->getEntityManager(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->receiveSocketException(handle, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Channel closed while writing."_j));
        return;
    }
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->getEntityManager(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->primarySocketAvailable(socket, handle);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_this->PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->getEntityManager(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->receiveSocketException(handle, e);
}

java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::toString()
{
    return ::java::lang::StringBuilder().append(u"PriorityTLi: Primary Socket shim to "_j)->append(static_cast< ::java::lang::Object* >(i))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_openPrimarySocketHelper_3_receiveResult_3_2::getClass0()
{
    return class_();
}

