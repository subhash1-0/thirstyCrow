// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_openSocket_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_openSocket_2_receiveResult_2_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_openSocket_2::TableTransprotLayerImpl_openSocket_2(TableTransprotLayerImpl *TableTransprotLayerImpl_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_this(TableTransprotLayerImpl_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_openSocket_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(ret, ex);
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_openSocket_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    auto writeMe = ::java::nio::ByteBuffer::allocate(1);
    npc(writeMe)->put(TableTransprotLayerImpl::PASSTHROUGH);
    npc(writeMe)->clear();
    new ::org::mpisws::p2p::transport::util::BufferWriter(writeMe, sock, new TableTransprotLayerImpl_openSocket_2_receiveResult_2_1(this, deliverSocketToMe, ret), false);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_openSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_openSocket_2::getClass0()
{
    return class_();
}

