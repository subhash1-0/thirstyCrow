// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-5849182107707420256LL) };

public: /* protected */
    int32_t id {  };
    char16_t tag {  };
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::rice::p2p::commonapi::Id* dest {  };
    bool isResponse_ {  };
protected:
    void ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);

public:
    int32_t getPriority() override;
    virtual int32_t getUID();
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual ::rice::p2p::commonapi::Id* getDestination();
    virtual bool isResponse();
    virtual char16_t getTag();
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public: /* protected */
    GlacierMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag);

public:
    GlacierMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GlacierMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
