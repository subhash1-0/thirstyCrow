// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCInsertMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/InsertMessage.hpp>

struct default_init_tag;

class rice::p2p::past::gc::messaging::GCInsertMessage
    : public ::rice::p2p::past::messaging::InsertMessage
{

public:
    typedef ::rice::p2p::past::messaging::InsertMessage super;
    static constexpr int16_t TYPE { int16_t(9) };

public: /* protected */
    int64_t expiration {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::past::PastContent* content, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual int64_t getExpiration();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GCInsertMessage* buildGC(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;

    // Generated

public:
    GCInsertMessage(int32_t uid, ::rice::p2p::past::PastContent* content, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    GCInsertMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd);
protected:
    GCInsertMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
