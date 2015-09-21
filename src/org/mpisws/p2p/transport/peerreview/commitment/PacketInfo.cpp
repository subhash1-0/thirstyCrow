// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/PacketInfo.java
#include <org/mpisws/p2p/transport/peerreview/commitment/PacketInfo.hpp>

#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>

org::mpisws::p2p::transport::peerreview::commitment::PacketInfo::PacketInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::PacketInfo::PacketInfo(::java::nio::ByteBuffer* msg, ::java::util::Map* options) 
    : PacketInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg,options);
}

void org::mpisws::p2p::transport::peerreview::commitment::PacketInfo::ctor(::java::nio::ByteBuffer* msg, ::java::util::Map* options)
{
    super::ctor();
    this->msg = msg;
    this->options = options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::PacketInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.PacketInfo", 57);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::PacketInfo::getClass0()
{
    return class_();
}

