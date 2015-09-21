// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManager.java

#pragma once

#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::replication::manager::ReplicationManager
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::replication::Replication* getReplication() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
