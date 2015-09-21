// Generated from /pastry-2.1/src/rice/p2p/commonapi/RouteMessage.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::RouteMessage
    : public virtual ::java::io::Serializable
{
    virtual Id* getDestinationId() = 0;
    virtual NodeHandle* getNextHopHandle() = 0;
    virtual Message* getMessage() = 0;
    virtual Message* getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */ = 0;
    virtual void setDestinationId(Id* id) = 0;
    virtual void setNextHopHandle(NodeHandle* nextHop) = 0;
    virtual void setMessage(Message* message) = 0;
    virtual void setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
