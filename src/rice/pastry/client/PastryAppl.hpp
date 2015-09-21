// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::client::PastryAppl
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* deserializer {  };
    ::java::lang::String* instance {  };
    ::rice::pastry::PastryNode* thePastryNode {  };
    int32_t address {  };
    ::rice::environment::logging::Logger* logger {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);
    void ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance);
    void ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
    void ctor(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, ::rice::environment::logging::Logger* logger);
    void ctor(::rice::pastry::PastryNode* pn, int32_t port);

public:
    virtual void register_();
    virtual int32_t getAddress();
    virtual void receiveMessageInternal(::rice::pastry::messaging::RawMessageDelivery* msg);

public: /* protected */
    virtual void setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* deserializer);

public:
    virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer();
    virtual void receiveMessage(::rice::pastry::messaging::Message* msg);
    ::rice::pastry::Id* getNodeId();
    virtual ::rice::pastry::NodeHandle* getNodeHandle();
    virtual bool routeMsgDirect(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt);
    virtual void routeMsg(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt);
    virtual ::rice::p2p::commonapi::MessageReceipt* routeMsg(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg, ::rice::pastry::routing::SendOptions* opt, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe);
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet();
    virtual ::rice::pastry::routing::RoutingTable* getRoutingTable();
    virtual bool isClosest(::rice::pastry::Id* key);
    virtual void messageForAppl(::rice::pastry::messaging::Message* msg) = 0;
    virtual bool enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt);
    virtual void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded);
    virtual void routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded);
    virtual void notifyReady();
    virtual bool deliverWhenNotReady();
    virtual void destroy();
    virtual void connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout);
    virtual void accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver);

public: /* protected */
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver {  };

public:
    virtual bool canReceiveSocket();
    virtual void finishReceiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */;

    // Generated
    PastryAppl(::rice::pastry::PastryNode* pn);
    PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance);
    PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
    PastryAppl(::rice::pastry::PastryNode* pn, ::java::lang::String* instance, int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, ::rice::environment::logging::Logger* logger);
    PastryAppl(::rice::pastry::PastryNode* pn, int32_t port);
protected:
    PastryAppl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryAppl_LeafSetObserver;
    friend class PastryAppl_RouteSetObserver;
    friend class PastryAppl_routeMsg_1;
    friend class PastryAppl_routeMsg_2;
};
