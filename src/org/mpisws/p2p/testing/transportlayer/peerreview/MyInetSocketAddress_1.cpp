// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::MyInetSocketAddress_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

constexpr int8_t org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::IPV4;

constexpr int8_t org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::IPV6;

constexpr int32_t org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::IPV4_BYTES;

constexpr int32_t org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::IPV6_BYTES;

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b) /* throws(IOException) */
{
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
    return new MyInetSocketAddress(::java::net::InetAddress::getByAddress(addr), int32_t(65535) & port);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::serialize(MyInetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */
{
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

void org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf)
{ 
    serialize(dynamic_cast< MyInetSocketAddress* >(i), buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1::getClass0()
{
    return class_();
}

