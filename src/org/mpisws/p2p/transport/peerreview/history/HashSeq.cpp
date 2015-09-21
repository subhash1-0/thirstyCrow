// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/HashSeq.java
#include <org/mpisws/p2p/transport/peerreview/history/HashSeq.hpp>

#include <Array.hpp>

org::mpisws::p2p::transport::peerreview::history::HashSeq::HashSeq(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::HashSeq::HashSeq(::int8_tArray* h, int64_t s) 
    : HashSeq(*static_cast< ::default_init_tag* >(0))
{
    ctor(h,s);
}

void org::mpisws::p2p::transport::peerreview::history::HashSeq::ctor(::int8_tArray* h, int64_t s)
{
    super::ctor();
    hash = h;
    seq = s;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::HashSeq::getHash()
{
    return hash;
}

int64_t org::mpisws::p2p::transport::peerreview::history::HashSeq::getSeq()
{
    return seq;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::HashSeq::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.HashSeq", 51);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::HashSeq::getClass0()
{
    return class_();
}

