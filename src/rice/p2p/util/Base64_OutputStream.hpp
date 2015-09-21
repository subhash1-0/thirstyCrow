// Generated from /pastry-2.1/src/rice/p2p/util/Base64.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/FilterOutputStream.hpp>

struct default_init_tag;

class rice::p2p::util::Base64_OutputStream
    : public ::java::io::FilterOutputStream
{

public:
    typedef ::java::io::FilterOutputStream super;

private:
    int32_t options {  };
    bool encode {  };
    int32_t position {  };
    ::int8_tArray* buffer {  };
    int32_t bufferLength {  };
    int32_t lineLength {  };
    bool breakLines {  };
    ::int8_tArray* b4 {  };
    bool suspendEncoding_ {  };
protected:
    void ctor(::java::io::OutputStream* out);
    void ctor(::java::io::OutputStream* out, int32_t options);

public:
    void write(int32_t theByte) /* throws(java.io.IOException) */ override;
    void write(::int8_tArray* theBytes, int32_t off, int32_t len) /* throws(java.io.IOException) */ override;
    virtual void flushBase64() /* throws(java.io.IOException) */;
    void close() /* throws(java.io.IOException) */ override;
    virtual void suspendEncoding() /* throws(java.io.IOException) */;
    virtual void resumeEncoding();

    // Generated
    Base64_OutputStream(::java::io::OutputStream* out);
    Base64_OutputStream(::java::io::OutputStream* out, int32_t options);
protected:
    Base64_OutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
    friend class Base64;
    friend class Base64_InputStream;
};
