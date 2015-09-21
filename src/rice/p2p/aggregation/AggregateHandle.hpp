// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::aggregation::AggregateHandle
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::rawserialization::RawGCPastContentHandle
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
    ::rice::p2p::commonapi::NodeHandle* handle {  };
    int64_t version {  };
    int64_t expiration {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration);

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
    int64_t getVersion() override;
    int64_t getExpiration() override;
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    AggregateHandle(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration);
    AggregateHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    AggregateHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
