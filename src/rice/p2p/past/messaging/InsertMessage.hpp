// Generated from /pastry-2.1/src/rice/p2p/past/messaging/InsertMessage.java

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

class rice::p2p::past::messaging::InsertMessage
    : public ContinuationMessage
{

public:
    typedef ContinuationMessage super;
    static constexpr int16_t TYPE { int16_t(4) };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-7027957470028259605LL) };

public: /* protected */
    ::rice::p2p::past::rawserialization::RawPastContent* content {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    void ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::past::PastContent* getContent();
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

public: /* protected */
    virtual void serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

public:
    static InsertMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */;

    // Generated

public:
    InsertMessage(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);
    InsertMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public: /* protected */
    InsertMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd);
protected:
    InsertMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
