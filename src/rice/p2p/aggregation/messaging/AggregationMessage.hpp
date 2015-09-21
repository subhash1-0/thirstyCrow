// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/AggregationMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::p2p::aggregation::messaging::AggregationMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t id {  };
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::rice::p2p::commonapi::Id* dest {  };
protected:
    void ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    int32_t getPriority() override;
    virtual int32_t getUID();
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual ::rice::p2p::commonapi::Id* getDestination();

    // Generated

public: /* protected */
    AggregationMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
protected:
    AggregationMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
