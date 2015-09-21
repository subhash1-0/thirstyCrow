// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl_ReplicationImpl_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    ReplicationImpl_ReplicationImpl_1(ReplicationImpl *ReplicationImpl_this);
    static ::java::lang::Class *class_();
    ReplicationImpl *ReplicationImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_replicate_2_receiveResult_2_1;
    friend class ReplicationImpl_deliver_3;
    friend class ReplicationImpl_deliver_4;
    friend class ReplicationImpl_BloomFilterExecutable;
};
