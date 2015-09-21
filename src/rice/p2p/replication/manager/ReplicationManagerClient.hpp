// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::replication::manager::ReplicationManagerClient
    : public virtual ::java::lang::Object
{
    virtual void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command) = 0;
    virtual void remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;
    virtual ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) = 0;
    virtual bool exists(::rice::p2p::commonapi::Id* id) = 0;
    virtual void existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;
    virtual void reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
