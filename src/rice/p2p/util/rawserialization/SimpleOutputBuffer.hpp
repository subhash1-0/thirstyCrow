// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SimpleOutputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/DataOutputStream.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::SimpleOutputBuffer
    : public ::java::io::DataOutputStream
    , public virtual ::rice::p2p::commonapi::rawserialization::OutputBuffer
{

public:
    typedef ::java::io::DataOutputStream super;

public: /* package */
    ::java::io::ByteArrayOutputStream* baos {  };
protected:
    void ctor(int32_t size);
    void ctor();

public:
    void writeByte(int8_t v) /* throws(IOException) */ override;
    void writeChar(char16_t v) /* throws(IOException) */ override;
    void writeShort(int16_t v) /* throws(IOException) */ override;
    int32_t bytesRemaining() override;
    virtual ::int8_tArray* getBytes();
    virtual ::java::nio::ByteBuffer* getByteBuffer();
    virtual int32_t getWritten();

    // Generated
    SimpleOutputBuffer(int32_t size);
    SimpleOutputBuffer();
protected:
    SimpleOutputBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::int8_tArray* b, int32_t off, int32_t len);
    virtual void writeBoolean(bool v);
    virtual void writeDouble(double v);
    virtual void writeFloat(float v);
    virtual void writeInt(int32_t v);
    virtual void writeLong(int64_t v);
    virtual void writeUTF(::java::lang::String* str);
    void write(int32_t arg0);
    void writeByte(int32_t arg0);
    void writeChar(int32_t arg0);
    void writeShort(int32_t arg0);

public: /* package */
    static int32_t writeUTF(::java::lang::String* arg0, ::java::io::DataOutput* arg1);

public:
    void write(::int8_tArray* b);

private:
    virtual ::java::lang::Class* getClass0();
};
