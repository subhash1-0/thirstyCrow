// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl_replicate_2_receiveResult_2_1
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;
    void receiveResult(::java::lang::Object* o) override;

    // Generated
    ReplicationImpl_replicate_2_receiveResult_2_1(ReplicationImpl_replicate_2 *ReplicationImpl_replicate_2_this, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::IdRange* range, ::rice::p2p::commonapi::IdRange* ourRange, ::rice::p2p::util::IdBloomFilter* ourFilter, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();
    ReplicationImpl_replicate_2 *ReplicationImpl_replicate_2_this;
    ::rice::p2p::commonapi::NodeHandle* handle;
    ::rice::p2p::commonapi::IdRange* range;
    ::rice::p2p::commonapi::IdRange* ourRange;
    ::rice::p2p::util::IdBloomFilter* ourFilter;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl;
    friend class ReplicationImpl_ReplicationImpl_1;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_deliver_3;
    friend class ReplicationImpl_deliver_4;
    friend class ReplicationImpl_BloomFilterExecutable;
};
