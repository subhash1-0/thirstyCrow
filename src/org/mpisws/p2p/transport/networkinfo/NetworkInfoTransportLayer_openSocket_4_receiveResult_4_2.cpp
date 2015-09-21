// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_openSocket_4.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2(NetworkInfoTransportLayer_openSocket_4 *NetworkInfoTransportLayer_openSocket_4_this, ::int8_tArray* header, ::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_openSocket_4_this(NetworkInfoTransportLayer_openSocket_4_this)
    , header(header)
    , i(i)
    , deliverSocketToMe(deliverSocketToMe)
    , cancellable(cancellable)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::init()
{
    buf = ::java::nio::ByteBuffer::wrap(header);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead)
        throw new ::java::io::IOException(u"Never asked to read!"_j);

    if(!canWrite)
        throw new ::java::io::IOException(u"Can't write!"_j);

    auto ret = npc(socket)->write(buf);
    if(ret < 0) {
        npc(socket)->close();
        return;
    }
    if(npc(NetworkInfoTransportLayer_openSocket_4_this->NetworkInfoTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(NetworkInfoTransportLayer_openSocket_4_this->NetworkInfoTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(npc(header)->length)
            ->append(u") wrote "_j)
            ->append(ret)
            ->append(u".  Remaining:"_j)
            ->append(npc(buf)->remaining())->toString());

    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(deliverSocketToMe)->receiveResult(cancellable, socket);
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(deliverSocketToMe)->receiveException(cancellable, e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2::getClass0()
{
    return class_();
}

