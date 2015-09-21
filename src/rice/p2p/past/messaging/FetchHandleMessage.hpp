// Generated from /pastry-2.1/src/rice/p2p/past/messaging/FetchHandleMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::FetchHandleMessage
    : public ContinuationMessage
{

public:
    typedef ContinuationMessage super;
    static constexpr int16_t TYPE { int16_t(2) };

private:
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::commonapi::Id* getId();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static FetchHandleMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd) /* throws(IOException) */;

    // Generated

public:
    FetchHandleMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    FetchHandleMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* pchd);
protected:
    FetchHandleMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
