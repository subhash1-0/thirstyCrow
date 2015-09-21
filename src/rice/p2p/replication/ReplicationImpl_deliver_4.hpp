// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Executable.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl_deliver_4
    : public virtual ::java::lang::Object
    , public virtual ::rice::Executable
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::String* toString() override;
    ::java::lang::Object* execute() override;

    // Generated
    ReplicationImpl_deliver_4(ReplicationImpl *ReplicationImpl_this, int32_t j, ::rice::p2p::replication::messaging::RequestMessage* rm);
    static ::java::lang::Class *class_();
    ReplicationImpl *ReplicationImpl_this;
    int32_t j;
    ::rice::p2p::replication::messaging::RequestMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl;
    friend class ReplicationImpl_ReplicationImpl_1;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_replicate_2_receiveResult_2_1;
    friend class ReplicationImpl_deliver_3;
    friend class ReplicationImpl_BloomFilterExecutable;
};
