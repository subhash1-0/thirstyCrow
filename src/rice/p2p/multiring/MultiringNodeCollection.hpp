// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeCollection.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringNodeCollection
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    int32_t BASE {  };

public: /* protected */
    ::java::util::Vector* nodes {  };
protected:
    void ctor(MultiringNode* node, int32_t BASE);

public:
    virtual void addNode(MultiringNode* node);

public: /* protected */
    virtual void broadcastNewNode(MultiringNode* node);
    virtual ::rice::p2p::commonapi::MessageReceipt* route(RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options);
    virtual int32_t getLength(RingId* a);
    virtual int32_t getLengthOfSharedPrefix(RingId* a, RingId* b);

    // Generated

public:
    MultiringNodeCollection(MultiringNode* node, int32_t BASE);
protected:
    MultiringNodeCollection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
