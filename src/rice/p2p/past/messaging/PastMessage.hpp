// Generated from /pastry-2.1/src/rice/p2p/past/messaging/PastMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::PastMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-7195054010358285316LL) };

public: /* protected */
    int32_t id {  };
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::rice::p2p::commonapi::Id* dest {  };
    bool isResponse_ {  };
protected:
    void ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    int32_t getPriority() override;
    virtual int32_t getUID();
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual ::rice::p2p::commonapi::Id* getDestination();

public: /* protected */
    virtual void setResponse();

public:
    virtual bool isResponse();
    virtual void returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance) = 0;
    virtual void addHop(::rice::p2p::commonapi::NodeHandle* handle);
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated

public: /* protected */
    PastMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    PastMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    PastMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
