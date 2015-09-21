// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/ExposedByteArrayOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/io/ByteArrayOutputStream.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream
    : public ::java::io::ByteArrayOutputStream
{

public:
    typedef ::java::io::ByteArrayOutputStream super;
protected:
    void ctor(int32_t size);
    void ctor();

public:
    virtual ::int8_tArray* buf();

    // Generated
    ExposedByteArrayOutputStream(int32_t size);
    ExposedByteArrayOutputStream();
protected:
    ExposedByteArrayOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
