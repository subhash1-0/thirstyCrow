// Generated from /pastry-2.1/src/rice/p2p/commonapi/Endpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/NodeHandleReader.hpp>

struct rice::p2p::commonapi::Endpoint
    : public virtual ::rice::p2p::commonapi::rawserialization::NodeHandleReader
{
    virtual Id* getId() = 0;
    virtual MessageReceipt* route(Id* id, Message* message, NodeHandle* hint, DeliveryNotification* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual MessageReceipt* route(Id* id, Message* message, NodeHandle* hint, DeliveryNotification* deliverAckToMe) = 0;
    virtual MessageReceipt* route(Id* id, Message* message, NodeHandle* hint) = 0;
    virtual MessageReceipt* route(Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, NodeHandle* hint, DeliveryNotification* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual MessageReceipt* route(Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, NodeHandle* hint, DeliveryNotification* deliverAckToMe) = 0;
    virtual MessageReceipt* route(Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, NodeHandle* hint) = 0;
    virtual NodeHandleSet* localLookup(Id* id, int32_t num, bool safe) = 0;
    virtual NodeHandleSet* neighborSet(int32_t num) = 0;
    virtual NodeHandleSet* replicaSet(Id* id, int32_t maxRank) = 0;
    virtual NodeHandleSet* replicaSet(Id* id, int32_t maxRank, NodeHandle* root, NodeHandleSet* set) = 0;
    virtual IdRange* range(NodeHandle* handle, int32_t rank, Id* lkey) /* throws(RangeCannotBeDeterminedException) */ = 0;
    virtual IdRange* range(NodeHandle* handle, int32_t rank, Id* lkey, bool cumulative) /* throws(RangeCannotBeDeterminedException) */ = 0;
    virtual NodeHandle* getLocalNodeHandle() = 0;
    virtual CancellableTask* scheduleMessage(Message* message, int64_t delay) = 0;
    virtual CancellableTask* scheduleMessage(Message* message, int64_t delay, int64_t period) = 0;
    virtual CancellableTask* scheduleMessageAtFixedRate(Message* message, int64_t delay, int64_t period) = 0;
    virtual void process(::rice::Executable* task, ::rice::Continuation* command) = 0;
    virtual ::java::lang::String* getInstance() = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    virtual void accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver) = 0;
    virtual void connect(NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout) = 0;
    virtual void setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) = 0;
    virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer() = 0;
    virtual void setConsistentRouting(bool val) = 0;
    virtual bool routingConsistentFor(Id* id) = 0;
    virtual Id* readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ = 0;
    virtual ::java::util::List* networkNeighbors(int32_t num) = 0;
    virtual IdRange* readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ = 0;
    virtual NodeHandleSet* readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ = 0;
    /*NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf); (already declared) */
    virtual void register_() = 0;
    virtual int32_t proximity(NodeHandle* nh) = 0;
    virtual bool isAlive(NodeHandle* nh) = 0;
    virtual void setSendOptions(::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
