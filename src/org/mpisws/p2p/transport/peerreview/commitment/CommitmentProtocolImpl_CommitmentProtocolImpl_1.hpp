// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java

#pragma once

#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl_CommitmentProtocolImpl_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    CommitmentProtocolImpl_CommitmentProtocolImpl_1(CommitmentProtocolImpl *CommitmentProtocolImpl_this);
    static ::java::lang::Class *class_();
    CommitmentProtocolImpl *CommitmentProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommitmentProtocolImpl;
    friend class CommitmentProtocolImpl_initReceiveCache_2;
};
