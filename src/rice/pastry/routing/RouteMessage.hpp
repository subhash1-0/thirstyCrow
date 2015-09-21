// Generated from /pastry-2.1/src/rice/pastry/routing/RouteMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <java/io/Serializable.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>

struct default_init_tag;

class rice::pastry::routing::RouteMessage
    : public ::rice::pastry::messaging::PRawMessage
    , public virtual ::java::io::Serializable
    , public virtual ::rice::p2p::commonapi::RouteMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3492981895989180093LL) };

public:
    static constexpr int16_t TYPE { int16_t(-23525) };

private:
    ::rice::pastry::Id* target {  };
    ::rice::pastry::NodeHandle* destinationHandle {  };
    int8_t version {  };
    ::rice::pastry::NodeHandle* prevNode {  };
    SendOptions* opts {  };
    int32_t auxAddress {  };
    ::rice::pastry::NodeHandle* nextHop {  };

public:
    ::rice::pastry::messaging::Message* internalMsg {  };

private:
    ::rice::pastry::messaging::PRawMessage* rawInternalMsg {  };
    ::rice::p2p::commonapi::rawserialization::InputBuffer* serializedMsg {  };
    ::rice::pastry::PastryNode* pn {  };

public: /* package */
    bool hasSender {  };
    int8_t internalPriority {  };
    int16_t internalType {  };

public:
    int32_t numRetries {  };

private:
    RouteMessage_RMDeserializer* endpointDeserializer {  };
protected:
    void ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, int8_t serializeVersion);
    void ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion);
    void ctor(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion);
    void ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, int8_t serializeVersion);

private:
    static ::rice::pastry::messaging::PRawMessage* convert(::rice::pastry::messaging::Message* msg);
protected:
    void ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::PRawMessage* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion);
    void ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion);

public:
    virtual ::rice::pastry::Id* getTarget();
    virtual ::rice::pastry::NodeHandle* getPrevNode();
    virtual void setPrevNode(::rice::pastry::NodeHandle* n);
    virtual ::rice::pastry::NodeHandle* getNextHop();
    virtual void setNextHop(::rice::pastry::NodeHandle* nh);
    int32_t getPriority() override;
    virtual ::rice::pastry::messaging::Message* unwrap();
    virtual SendOptions* getOptions();
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Id* getDestinationId() override;
    ::rice::p2p::commonapi::NodeHandle* getNextHopHandle() override;
    ::rice::p2p::commonapi::Message* getMessage() override;
    ::rice::p2p::commonapi::Message* getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */ override;
    void setDestinationId(::rice::p2p::commonapi::Id* id) override;
    void setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop) override;
    void setMessage(::rice::p2p::commonapi::Message* message) override;
    void setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message) override;
    static ::rice::pastry::routing::RouteMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* prev, int8_t outputVersion) /* throws(IOException) */;
protected:
    void ctor(::rice::pastry::Id* target, int32_t auxAddress, ::rice::pastry::NodeHandle* prev, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* destinationHandle, int8_t serializeVersion) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::pastry::messaging::Message* unwrap(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */;
    int16_t getType() override;
    virtual int32_t getAuxAddress();
    virtual int16_t getInternalType();
    virtual void setDestinationHandle(::rice::pastry::NodeHandle* handle);
    virtual ::rice::pastry::NodeHandle* getDestinationHandle();

private:
    ::java::util::Map* options {  };

public:
    virtual ::java::util::Map* getTLOptions();
    virtual void setTLOptions(::java::util::Map* options);

public: /* package */
    ::rice::p2p::commonapi::Cancellable* tlCancellable {  };

public:
    virtual void setTLCancellable(::rice::p2p::commonapi::Cancellable* c);
    virtual bool cancel();

public: /* package */
    RouteMessageNotification* notifyMe {  };

public:
    virtual void setRouteMessageNotification(RouteMessageNotification* notification);
    virtual void sendSuccess(::rice::pastry::NodeHandle* nextHop);
    virtual bool sendFailed(::java::lang::Exception* e);

    // Generated
    RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, int8_t serializeVersion);
    RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion);
    RouteMessage(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion);
    RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, int8_t serializeVersion);
    RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::PRawMessage* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion);
    RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion);
    RouteMessage(::rice::pastry::Id* target, int32_t auxAddress, ::rice::pastry::NodeHandle* prev, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* destinationHandle, int8_t serializeVersion);
protected:
    RouteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class RouteMessage_RMDeserializer;
};
