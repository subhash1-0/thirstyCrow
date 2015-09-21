// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCLookupHandlesMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/LookupHandlesMessage.hpp>

struct default_init_tag;

class rice::p2p::past::gc::messaging::GCLookupHandlesMessage
    : public ::rice::p2p::past::messaging::LookupHandlesMessage
{

public:
    typedef ::rice::p2p::past::messaging::LookupHandlesMessage super;
    static constexpr int16_t TYPE { int16_t(10) };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GCLookupHandlesMessage* buildGC(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GCLookupHandlesMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    GCLookupHandlesMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GCLookupHandlesMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
