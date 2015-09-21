// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_runMaintenance_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    ReplicationManagerRegrTest_runMaintenance_1(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, int32_t j);
    static ::java::lang::Class *class_();
    ReplicationManagerRegrTest *ReplicationManagerRegrTest_this;
    int32_t j;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerRegrTest;
    friend class ReplicationManagerRegrTest_TestReplicationManagerClient;
};
