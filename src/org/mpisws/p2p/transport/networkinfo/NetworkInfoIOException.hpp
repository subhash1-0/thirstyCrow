// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoIOException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;
protected:
    void ctor(::java::lang::Exception* e);

    // Generated

public:
    NetworkInfoIOException(::java::lang::Exception* e);
protected:
    NetworkInfoIOException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
