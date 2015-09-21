// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaDeserializer.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/ObjectInputStream.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::JavaDeserializer
    : public ::java::io::ObjectInputStream
{

public:
    typedef ::java::io::ObjectInputStream super;

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
protected:
    void ctor(::java::io::InputStream* stream, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public: /* protected */
    ::java::lang::Object* resolveObject(::java::lang::Object* input) /* throws(IOException) */ override;

    // Generated

public:
    JavaDeserializer(::java::io::InputStream* stream, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    JavaDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
