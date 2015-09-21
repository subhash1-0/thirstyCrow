// Generated from /pastry-2.1/src/rice/p2p/past/messaging/ContinuationMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::p2p::past::messaging::ContinuationMessage
    : public PastMessage
    , public virtual ::rice::Continuation
{

public:
    typedef PastMessage super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(1321112527034107161LL) };

public: /* protected */
    ::java::lang::Object* response {  };
    ::java::lang::Exception* exception {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;
    void returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance) override;
    virtual ::java::lang::Object* getResponse();

private:
    static int8_t S_EMPTY_;
    static int8_t S_SUB_;
    static int8_t S_JAVA_RESPONSE_;
    static int8_t S_JAVA_EXCEPTION_;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    virtual void deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;

public: /* protected */
    int8_t serType {  };

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize) /* throws(IOException) */;

    // Generated

public: /* protected */
    ContinuationMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    ContinuationMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    ContinuationMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int8_t& S_EMPTY();
    static int8_t& S_SUB();
    static int8_t& S_JAVA_RESPONSE();
    static int8_t& S_JAVA_EXCEPTION();

private:
    virtual ::java::lang::Class* getClass0();
};
