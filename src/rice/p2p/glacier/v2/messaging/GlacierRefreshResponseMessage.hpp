// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(12) };

public: /* protected */
    ::rice::p2p::commonapi::IdRange* range {  };
    bool online {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::IdRange* range, bool online, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

public:
    virtual ::rice::p2p::commonapi::IdRange* getRange();
    virtual bool isOnline();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GlacierRefreshResponseMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GlacierRefreshResponseMessage(int32_t uid, ::rice::p2p::commonapi::IdRange* range, bool online, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag);

private:
    GlacierRefreshResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierRefreshResponseMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
