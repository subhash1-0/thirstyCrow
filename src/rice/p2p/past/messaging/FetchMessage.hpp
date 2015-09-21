// Generated from /pastry-2.1/src/rice/p2p/past/messaging/FetchMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::FetchMessage
    : public ContinuationMessage
{

public:
    typedef ContinuationMessage super;
    static constexpr int16_t TYPE { int16_t(3) };

private:
    ::rice::p2p::past::rawserialization::RawPastContentHandle* handle {  };
    bool cached {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::past::PastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    void ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::past::PastContentHandle* getHandle();
    virtual bool isCached();
    virtual void setCached();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static FetchMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */;

    // Generated

public:
    FetchMessage(int32_t uid, ::rice::p2p::past::PastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    FetchMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContentHandle* handle, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    FetchMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd);
protected:
    FetchMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
