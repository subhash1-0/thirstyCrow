// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierSyncMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierSyncMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(14) };

public: /* protected */
    ::rice::p2p::commonapi::IdRange* range {  };
    int32_t offsetFID {  };
    ::rice::p2p::glacier::v2::BloomFilter* BloomFilter {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* range, int32_t offsetFID, ::rice::p2p::glacier::v2::BloomFilter* BloomFilter, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

public:
    virtual int32_t getOffsetFID();
    virtual ::rice::p2p::commonapi::IdRange* getRange();
    virtual ::rice::p2p::glacier::v2::BloomFilter* getBloomFilter();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GlacierSyncMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GlacierSyncMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* range, int32_t offsetFID, ::rice::p2p::glacier::v2::BloomFilter* BloomFilter, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

private:
    GlacierSyncMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierSyncMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
