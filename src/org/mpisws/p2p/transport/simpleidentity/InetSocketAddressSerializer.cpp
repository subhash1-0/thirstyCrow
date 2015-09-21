// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.java
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::InetSocketAddressSerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::InetSocketAddressSerializer()
    : InetSocketAddressSerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int8_t org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::IPV4;

constexpr int8_t org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::IPV6;

constexpr int32_t org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::IPV4_BYTES;

constexpr int32_t org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::IPV6_BYTES;

java::net::InetSocketAddress* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::net::InetSocketAddress* i, ::java::util::Map* options) /* throws(IOException) */
{
    return deserializeAddress(b);
}

java::lang::Object* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::lang::Object* i, ::java::util::Map* options)
{ 
    return deserialize(b, dynamic_cast< ::java::net::InetSocketAddress* >(i), options);
}

void org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::serialize(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */
{
    serializeAddress(i, b);
}

void org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b)
{ 
    serialize(dynamic_cast< ::java::net::InetSocketAddress* >(i), b);
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::deserializeAddress(::rice::p2p::commonapi::rawserialization::InputBuffer* b) /* throws(IOException) */
{
    clinit();
    auto version = npc(b)->readByte();
    ::int8_tArray* addr;
    switch (version) {
    case IPV4:
        addr = new ::int8_tArray(IPV4_BYTES);
        break;
    case IPV6:
        addr = new ::int8_tArray(IPV6_BYTES);
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Incorrect IP version, expecting 4 or 6, got "_j)->append(version)->toString());
    }

    npc(b)->read(addr);
    auto port = npc(b)->readShort();
    return new ::java::net::InetSocketAddress(::java::net::InetAddress::getByAddress(addr), int32_t(65535) & port);
}

void org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::serializeAddress(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */
{
    clinit();
    auto addr = npc(npc(i)->getAddress())->getAddress();
    switch (npc(addr)->length) {
    case IPV4_BYTES:
        npc(b)->writeByte(IPV4);
        break;
    case IPV6_BYTES:
        npc(b)->writeByte(IPV6);
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Incorrect number of bytes for IPaddress, expecting 4 or 16, got "_j)->append(npc(addr)->length)->toString());
    }

    npc(b)->write(addr, 0, npc(addr)->length);
    npc(b)->writeShort(static_cast< int16_t >(npc(i)->getPort()));
}

int32_t org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::getSerializedLength(::java::net::InetSocketAddress* i)
{
    return npc(npc(npc(i)->getAddress())->getAddress())->length + int32_t(2) + int32_t(1);
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return deserializeAddress(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.simpleidentity.InetSocketAddressSerializer", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer::getClass0()
{
    return class_();
}

