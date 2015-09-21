// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl_initReceiveCache_2.hpp>

#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.hpp>

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor(arg0);
}

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, ::java::util::Map* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor(arg0);
}

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0, float arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor(arg0, arg1);
}

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0, float arg1, bool arg2)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommitmentProtocolImpl_this(CommitmentProtocolImpl_this)
{
    clinit();
    ctor(arg0, arg1, arg2);
}

bool org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::removeEldestEntry(::java::util::Map_Entry* eldest)
{
    return size() > CommitmentProtocolImpl_this->RECEIVE_CACHE_SIZE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2::getClass0()
{
    return class_();
}

