// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2(PriorityTransportLayerImpl_openSocket_2 *PriorityTransportLayerImpl_openSocket_2_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_openSocket_2_this(PriorityTransportLayerImpl_openSocket_2_this)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead || !canWrite)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"expected to write!  canRead:"_j)->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)->toString());

    npc(socket)->write(::java::nio::ByteBuffer::wrap(PriorityTransportLayerImpl::PASSTHROUGH_SOCKET()));
    if(deliverSocketToMe != nullptr)
        npc(deliverSocketToMe)->receiveResult(handle, socket);

}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    if(deliverSocketToMe != nullptr)
        npc(deliverSocketToMe)->receiveException(handle, e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_openSocket_2_receiveResult_2_2::getClass0()
{
    return class_();
}

