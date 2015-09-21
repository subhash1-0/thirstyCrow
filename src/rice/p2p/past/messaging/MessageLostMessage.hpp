// Generated from /pastry-2.1/src/rice/p2p/past/messaging/MessageLostMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::MessageLostMessage
    : public PastMessage
{

public:
    typedef PastMessage super;
    static constexpr int16_t TYPE { int16_t(7) };

private:
    static constexpr int64_t serialVersionUID { int64_t(-8664827144233122095LL) };

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
    ::rice::p2p::commonapi::NodeHandle* hint {  };
    ::java::lang::String* messageString {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint);

public:
    void returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance) override;
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    MessageLostMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint);
protected:
    MessageLostMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
