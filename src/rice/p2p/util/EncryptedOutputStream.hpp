// Generated from /pastry-2.1/src/rice/p2p/util/EncryptedOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class rice::p2p::util::EncryptedOutputStream
    : public ::java::io::OutputStream
{

public:
    typedef ::java::io::OutputStream super;
    int32_t BUFFER_SIZE {  };

public: /* protected */
    ::java::security::PublicKey* publicKey {  };
    ::int8_tArray* key {  };
    ::java::io::DataOutputStream* stream {  };
    ::int8_tArray* buffer {  };
    int32_t bufferLength {  };
protected:
    void ctor(::java::security::PublicKey* publicKey, ::java::io::OutputStream* stream, int32_t bufferSize) /* throws(IOException) */;

private:
    void writeHeader() /* throws(IOException) */;

public:
    void write(int32_t b) /* throws(IOException) */ override;
    void write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ override;

public: /* protected */
    virtual void writeBuffer() /* throws(IOException) */;

public:
    void flush() /* throws(IOException) */ override;
    void close() /* throws(IOException) */ override;

    // Generated
    EncryptedOutputStream(::java::security::PublicKey* publicKey, ::java::io::OutputStream* stream, int32_t bufferSize);
protected:
    EncryptedOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
