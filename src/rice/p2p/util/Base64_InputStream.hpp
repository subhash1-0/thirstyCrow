// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/FilterInputStream.hpp>

struct default_init_tag;

class rice::p2p::util::Base64_InputStream
    : public ::java::io::FilterInputStream
{

public:
    typedef ::java::io::FilterInputStream super;

private:
    int32_t options {  };
    bool encode {  };
    int32_t position {  };
    ::int8_tArray* buffer {  };
    int32_t bufferLength {  };
    int32_t numSigBytes {  };
    int32_t lineLength {  };
    bool breakLines {  };
protected:
    void ctor(::java::io::InputStream* in);
    void ctor(::java::io::InputStream* in, int32_t options);

public:
    int32_t read() /* throws(java.io.IOException) */ override;
    int32_t read(::int8_tArray* dest, int32_t off, int32_t len) /* throws(java.io.IOException) */ override;

    // Generated
    Base64_InputStream(::java::io::InputStream* in);
    Base64_InputStream(::java::io::InputStream* in, int32_t options);
protected:
    Base64_InputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
    friend class Base64;
    friend class Base64_OutputStream;
};
