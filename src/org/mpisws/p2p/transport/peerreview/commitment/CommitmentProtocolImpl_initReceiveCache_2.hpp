// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <java/util/LinkedHashMap.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_initReceiveCache_2
    : public ::java::util::LinkedHashMap
{

public:
    typedef ::java::util::LinkedHashMap super;

public: /* protected */
    bool removeEldestEntry(::java::util::Map_Entry* eldest) override;

    // Generated

public:
    CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this);
    CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0);
    CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, ::java::util::Map* arg0);
    CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0, float arg1);
    CommitmentProtocolImpl_initReceiveCache_2(CommitmentProtocolImpl *CommitmentProtocolImpl_this, int32_t arg0, float arg1, bool arg2);
    static ::java::lang::Class *class_();
    CommitmentProtocolImpl *CommitmentProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommitmentProtocolImpl;
    friend class CommitmentProtocolImpl_CommitmentProtocolImpl_1;
};
