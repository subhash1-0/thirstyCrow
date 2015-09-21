// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializer.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::JavaSerializer
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static void serialize(::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    JavaSerializer();
protected:
    JavaSerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
