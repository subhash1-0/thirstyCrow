// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/ContactDeserializer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::ContactDeserializer
    : public virtual ::java::lang::Object
{
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual ::java::nio::ByteBuffer* serialize(::java::lang::Object* i) /* throws(IOException) */ = 0;
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* sib) /* throws(IOException) */ = 0;
    virtual ::java::lang::Object* convert(::java::lang::Object* high) = 0;
    virtual ::java::util::Map* getOptions(::java::lang::Object* high) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
