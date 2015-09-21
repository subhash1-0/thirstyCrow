// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/Serializer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::simpleidentity::Serializer
    : public virtual ::java::lang::Object
{
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */ = 0;
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::lang::Object* i, ::java::util::Map* options) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
