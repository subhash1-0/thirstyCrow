// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::replication::manager::ReplicationManagerClient
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Node* node {  };
    ::rice::p2p::commonapi::IdSet* set {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command) override;
    void remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    virtual void insert(::rice::p2p::commonapi::Id* id);
    bool exists(::rice::p2p::commonapi::Id* id) override;
    void existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    ::java::lang::String* toString() override;

    // Generated
    ReplicationManagerRegrTest_TestReplicationManagerClient(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, ::rice::p2p::commonapi::Node* node);
protected:
    ReplicationManagerRegrTest_TestReplicationManagerClient(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ReplicationManagerRegrTest *ReplicationManagerRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerRegrTest;
    friend class ReplicationManagerRegrTest_runMaintenance_1;
};
