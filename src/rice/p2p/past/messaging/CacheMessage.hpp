// Generated from /pastry-2.1/src/rice/p2p/past/messaging/CacheMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::CacheMessage
    : public PastMessage
{

public:
    typedef PastMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::past::rawserialization::RawPastContent* content {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    void ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::past::PastContent* getContent();
    void returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance) override;
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static CacheMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;

    // Generated

public:
    CacheMessage(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    CacheMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    CacheMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd);
protected:
    CacheMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
