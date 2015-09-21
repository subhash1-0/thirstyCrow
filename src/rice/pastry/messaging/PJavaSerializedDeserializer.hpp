// Generated from /pastry-2.1/src/rice/pastry/messaging/PJavaSerializedDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/JavaSerializedDeserializer.hpp>

struct default_init_tag;

class rice::pastry::messaging::PJavaSerializedDeserializer
    : public JavaSerializedDeserializer
{

public:
    typedef JavaSerializedDeserializer super;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */ = 0;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    PJavaSerializedDeserializer(::rice::pastry::PastryNode* pn);
protected:
    PJavaSerializedDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
