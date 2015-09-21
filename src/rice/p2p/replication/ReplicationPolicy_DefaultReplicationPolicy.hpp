// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationPolicy.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/replication/ReplicationPolicy.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy
    : public virtual ::java::lang::Object
    , public virtual ReplicationPolicy
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::IdSet* difference(::rice::p2p::commonapi::IdSet* local, ::rice::p2p::commonapi::IdSet* remote, ::rice::p2p::commonapi::IdFactory* factory) override;

    // Generated
    ReplicationPolicy_DefaultReplicationPolicy();
protected:
    ReplicationPolicy_DefaultReplicationPolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationPolicy;
};
