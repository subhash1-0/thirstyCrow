// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/InsufficientBytesException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::InsufficientBytesException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

private:
    int32_t needed {  };
    int32_t available {  };
protected:
    void ctor(int32_t needed, int32_t available);

private:
    int32_t getBytesAvailable();
    int32_t getBytesNeeded();

    // Generated

public:
    InsufficientBytesException(int32_t needed, int32_t available);
protected:
    InsufficientBytesException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
