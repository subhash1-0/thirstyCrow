// Generated from /pastry-2.1/src/rice/p2p/util/EncryptedInputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>

struct default_init_tag;

class rice::p2p::util::EncryptedInputStream
    : public ::java::io::InputStream
{

public:
    typedef ::java::io::InputStream super;

public: /* protected */
    ::java::security::PrivateKey* privateKey {  };
    ::int8_tArray* key {  };
    ::java::io::DataInputStream* stream {  };
    ::int8_tArray* buffer {  };
    int32_t bufferLength {  };
protected:
    void ctor(::java::security::PrivateKey* privateKey, ::java::io::InputStream* stream) /* throws(IOException) */;

private:
    void readHeader() /* throws(IOException) */;

public:
    int32_t read() /* throws(IOException) */ override;
    int32_t read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;

public: /* protected */
    virtual void readBuffer() /* throws(IOException) */;

public:
    int32_t available() /* throws(IOException) */ override;
    void close() /* throws(IOException) */ override;

    // Generated
    EncryptedInputStream(::java::security::PrivateKey* privateKey, ::java::io::InputStream* stream);
protected:
    EncryptedInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* b);

private:
    virtual ::java::lang::Class* getClass0();
};
