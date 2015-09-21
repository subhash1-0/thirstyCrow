// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/exception/StalledSocketException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/exception/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::exception::StalledSocketException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* protected */
    ::java::lang::Object* addr {  };
protected:
    void ctor(::java::lang::Object* addr, ::java::lang::String* s);
    void ctor(::java::net::InetSocketAddress* addr);

public:
    virtual ::java::lang::Object* getIdentifier();

    // Generated
    StalledSocketException(::java::lang::Object* addr, ::java::lang::String* s);
    StalledSocketException(::java::net::InetSocketAddress* addr);
protected:
    StalledSocketException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
