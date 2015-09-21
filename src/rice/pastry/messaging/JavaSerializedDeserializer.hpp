// Generated from /pastry-2.1/src/rice/pastry/messaging/JavaSerializedDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::pastry::messaging::JavaSerializedDeserializer
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };

private:
    bool deserializeOnlyTypeZero {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual void setAlwaysUseJavaSerialization(bool val);
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    JavaSerializedDeserializer(::rice::pastry::PastryNode* pn);
protected:
    JavaSerializedDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
