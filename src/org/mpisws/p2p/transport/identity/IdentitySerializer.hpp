// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentitySerializer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::identity::IdentitySerializer
    : public virtual ::java::lang::Object
{
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::java::lang::Object* i) /* throws(IOException) */ = 0;
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* l) /* throws(IOException) */ = 0;
    virtual ::java::lang::Object* translateDown(::java::lang::Object* i) = 0;
    virtual ::java::lang::Object* translateUp(::java::lang::Object* i) = 0;
    virtual void addSerializerListener(SerializerListener* listener) = 0;
    virtual void removeSerializerListener(SerializerListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
