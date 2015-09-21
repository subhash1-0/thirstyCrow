// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::p2p::scribe::ScribeImpl_ScribeImpl_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    ScribeImpl_ScribeImpl_1(ScribeImpl *ScribeImpl_this);
    static ::java::lang::Class *class_();
    ScribeImpl *ScribeImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeImpl;
    friend class ScribeImpl_ScribeClientConverter;
    friend class ScribeImpl_TopicManager;
    friend class ScribeImpl_destroy_2;
};
