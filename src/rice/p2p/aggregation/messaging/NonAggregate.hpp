// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/NonAggregate.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

struct default_init_tag;

class rice::p2p::aggregation::messaging::NonAggregate
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::rawserialization::RawPastContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(2) };
    ::rice::p2p::past::rawserialization::RawPastContent* content {  };
protected:
    void ctor(::rice::p2p::past::PastContent* content);
    void ctor(::rice::p2p::past::rawserialization::RawPastContent* subContent);

public:
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;
    ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) override;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isMutable() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::RawPastContent* subContent, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;

    // Generated

public:
    NonAggregate(::rice::p2p::past::PastContent* content);
    NonAggregate(::rice::p2p::past::rawserialization::RawPastContent* subContent);
    NonAggregate(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::RawPastContent* subContent, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd);
protected:
    NonAggregate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
