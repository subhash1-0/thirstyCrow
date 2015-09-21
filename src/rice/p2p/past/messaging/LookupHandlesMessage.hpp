// Generated from /pastry-2.1/src/rice/p2p/past/messaging/LookupHandlesMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::LookupHandlesMessage
    : public ContinuationMessage
{

public:
    typedef ContinuationMessage super;
    static constexpr int16_t TYPE { int16_t(5) };

private:
    ::rice::p2p::commonapi::Id* id {  };
    int32_t max {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::commonapi::Id* getId();
    virtual int32_t getMax();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

public: /* protected */
    virtual void serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

public:
    static LookupHandlesMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    LookupHandlesMessage(int32_t uid, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public: /* protected */
    LookupHandlesMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    LookupHandlesMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
