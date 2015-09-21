// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_handleIdRequest_8.hpp>

#include <java/lang/Byte.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>
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

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::NetworkInfoTransportLayer_handleIdRequest_8(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , socket(socket)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::receiveResult(::java::nio::ByteBuffer* result)
{
    auto index = npc(result)->get();
    if(java_cast< ::int8_tArray* >(npc(NetworkInfoTransportLayer_this->serializedIds)->get(::java::lang::Byte::valueOf(index))) == nullptr) {
        npc(socket)->close();
        return;
    }
    new ::org::mpisws::p2p::transport::util::BufferWriter(::java::nio::ByteBuffer::wrap(java_cast< ::int8_tArray* >(npc(NetworkInfoTransportLayer_this->serializedIds)->get(::java::lang::Byte::valueOf(index)))), socket, nullptr);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::nio::ByteBuffer* >(result));
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::receiveException(::java::lang::Exception* exception)
{
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_handleIdRequest_8::getClass0()
{
    return class_();
}

