// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/MemoryExpiredException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::MemoryExpiredException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;
protected:
    void ctor(::java::lang::String* string);

    // Generated

public:
    MemoryExpiredException(::java::lang::String* string);
protected:
    MemoryExpiredException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
