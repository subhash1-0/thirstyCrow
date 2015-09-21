// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringRouteMessage.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringRouteMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::RouteMessage
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::RouteMessage* message {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::RouteMessage* message);

public: /* protected */
    virtual ::rice::p2p::commonapi::RouteMessage* getRouteMessage();

public:
    ::rice::p2p::commonapi::Id* getDestinationId() override;
    ::rice::p2p::commonapi::NodeHandle* getNextHopHandle() override;
    ::rice::p2p::commonapi::Message* getMessage() override;
    ::rice::p2p::commonapi::Message* getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */ override;
    void setDestinationId(::rice::p2p::commonapi::Id* id) override;
    void setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop) override;
    void setMessage(::rice::p2p::commonapi::Message* message) override;
    void setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message) override;

    // Generated

public: /* protected */
    MultiringRouteMessage(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::RouteMessage* message);
protected:
    MultiringRouteMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
