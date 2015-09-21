// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializationException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::JavaSerializationException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    ::java::lang::Object* cantSerialize {  };
protected:
    void ctor(::java::lang::Object* o, ::java::lang::Exception* e);

public:
    virtual ::java::lang::Object* getUnserializable();

    // Generated
    JavaSerializationException(::java::lang::Object* o, ::java::lang::Exception* e);
protected:
    JavaSerializationException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
