// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_incomingSocket_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
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

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_incomingSocket_1::PriorityTransportLayerImpl_incomingSocket_1(PriorityTransportLayerImpl *PriorityTransportLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* s)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_this(PriorityTransportLayerImpl_this)
    , s(s)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_incomingSocket_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(socket != s)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Sockets not equal!!! s:"_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u" socket:"_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    if(canWrite || !canRead)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Should only be able to read! canRead:"_j)->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)->toString());

    auto hdr = ::java::nio::ByteBuffer::allocate(1);
    int32_t ret;
    try {
        ret = static_cast< int32_t >(npc(socket)->read(hdr));
    } catch (::java::io::IOException* ioe) {
        npc(socket)->close();
        return;
    }
    {
        int8_t val;
        switch (ret) {
        case -int32_t(1):
            npc(socket)->close();
            break;
        case int32_t(0):
            npc(socket)->register_(true, false, this);
            break;
        case int32_t(1):
            npc(hdr)->flip();
            val = npc(hdr)->get();
            switch (val) {
            case PriorityTransportLayerImpl::PASSTHROUGH_SOCKET_B:
                npc(PriorityTransportLayerImpl_this->callback)->incomingSocket(s);
                break;
            case PriorityTransportLayerImpl::PRIMARY_SOCKET_B:
                if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opened Primary Socket from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))->toString());

                npc(PriorityTransportLayerImpl_this->getEntityManager(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))->primarySocketAvailable(s, nullptr);
                break;
            case PriorityTransportLayerImpl::BIG_MSG_SOCKET_B:
                if(npc(PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opened BIG Message Socket from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))->toString());

                npc(PriorityTransportLayerImpl_this->getEntityManager(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))->handleBigMsgSocket(s);
                break;
            }

            break;
        default:
            npc(socket)->close();
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Read "_j)->append(ret)
                ->append(u" bytes?  Not good.  Expected to read 1 byte."_j)->toString());
        }
    }

}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_incomingSocket_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(PriorityTransportLayerImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_incomingSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_incomingSocket_1::getClass0()
{
    return class_();
}

