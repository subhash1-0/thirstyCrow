// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationPolicy.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::replication::ReplicationPolicy
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::IdSet* difference(::rice::p2p::commonapi::IdSet* local, ::rice::p2p::commonapi::IdSet* remote, ::rice::p2p::commonapi::IdFactory* factory) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
