// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializedMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::JavaSerializedMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::Message* msg {  };
protected:
    void ctor(::rice::p2p::commonapi::Message* msg);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::p2p::commonapi::Message* getMessage();
    int32_t getPriority() override;
    ::java::lang::String* toString() override;

    // Generated
    JavaSerializedMessage(::rice::p2p::commonapi::Message* msg);
protected:
    JavaSerializedMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
