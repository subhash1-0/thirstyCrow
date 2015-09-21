// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationClient.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::replication::ReplicationClient
    : public virtual ::java::lang::Object
{
    virtual void fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void setRange(::rice::p2p::commonapi::IdRange* range) = 0;
    virtual ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
