// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1(NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1 *NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_this, ::java::nio::ByteBuffer* writeMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_this(NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_this)
    , writeMe(writeMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesWritten = npc(socket)->write(writeMe);
    if(bytesWritten < 0) {
        npc(socket)->close();
        return;
    }
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(socket)->close();
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1::getClass0()
{
    return class_();
}

