// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1(NetworkInfoTransportLayer_handleProbeRequest_9 *NetworkInfoTransportLayer_handleProbeRequest_9_this, ::org::mpisws::p2p::transport::P2PSocket* socket)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_handleProbeRequest_9_this(NetworkInfoTransportLayer_handleProbeRequest_9_this)
    , socket(socket)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::receiveResult(::java::lang::Boolean* result)
{
    returnResult(npc(result)->booleanValue());
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::Boolean* >(result));
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::receiveException(::java::lang::Exception* exception)
{
    returnResult(false);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::returnResult(bool ret)
{
    auto const writeMe = ::java::nio::ByteBuffer::allocate(1);
    npc(writeMe)->put(ret ? static_cast< int8_t >(int32_t(1)) : static_cast< int8_t >(int32_t(0)));
    npc(writeMe)->flip();
    try {
        (new NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1(this, writeMe))->receiveSelectResult(socket, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(socket)->close();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1::getClass0()
{
    return class_();
}

