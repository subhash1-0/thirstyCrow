// Generated from /pastry-2.1/src/rice/p2p/past/Past.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::past::Past
    : public virtual ::java::lang::Object
{
    virtual void insert(PastContent* obj, ::rice::Continuation* command) = 0;
    virtual void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) = 0;
    virtual void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command) = 0;
    virtual void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command) = 0;
    virtual void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command) = 0;
    virtual void fetch(PastContentHandle* handle, ::rice::Continuation* command) = 0;
    virtual ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() = 0;
    virtual int32_t getReplicationFactor() = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    virtual ::java::lang::String* getInstance() = 0;
    virtual void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer) = 0;
    virtual void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
