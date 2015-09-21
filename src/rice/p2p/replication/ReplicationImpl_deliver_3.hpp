// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/fwd-pastry-2.1.hpp>
#include <rice/Continuation_ListenerContinuation.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl_deliver_3
    : public ::rice::Continuation_ListenerContinuation
{

public:
    typedef ::rice::Continuation_ListenerContinuation super;
    void receiveResult(::java::lang::Object* o) override;

    // Generated
    ReplicationImpl_deliver_3(ReplicationImpl *ReplicationImpl_this, ::rice::p2p::replication::messaging::RequestMessage* rm, ::java::lang::String* name, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    ReplicationImpl *ReplicationImpl_this;
    ::rice::p2p::replication::messaging::RequestMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl;
    friend class ReplicationImpl_ReplicationImpl_1;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_replicate_2_receiveResult_2_1;
    friend class ReplicationImpl_deliver_4;
    friend class ReplicationImpl_BloomFilterExecutable;
};
