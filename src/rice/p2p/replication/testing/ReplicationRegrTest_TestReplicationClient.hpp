// Generated from /pastry-2.1/src/rice/p2p/replication/testing/ReplicationRegrTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/testing/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>

struct default_init_tag;

class rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::replication::ReplicationClient
{

public:
    typedef ::java::lang::Object super;
    ::rice::persistence::MemoryStorage* storage {  };
    ::rice::p2p::commonapi::Node* node {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    void fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void setRange(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    virtual void insert(::rice::p2p::commonapi::Id* id);
    ::java::lang::String* toString() override;

    // Generated
    ReplicationRegrTest_TestReplicationClient(ReplicationRegrTest *ReplicationRegrTest_this, ::rice::p2p::commonapi::Node* node);
protected:
    ReplicationRegrTest_TestReplicationClient(ReplicationRegrTest *ReplicationRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ReplicationRegrTest *ReplicationRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationRegrTest;
};
