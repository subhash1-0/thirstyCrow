// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/FileOutputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/io/DataOutputStream.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::FileOutputBuffer
    : public ::java::io::DataOutputStream
    , public virtual ::rice::p2p::commonapi::rawserialization::OutputBuffer
{

public:
    typedef ::java::io::DataOutputStream super;
protected:
    void ctor(::java::io::File* f, bool append) /* throws(FileNotFoundException) */;
    void ctor(::java::io::File* f) /* throws(FileNotFoundException) */;
    void ctor(::java::lang::String* fileName) /* throws(FileNotFoundException) */;

public:
    int32_t bytesRemaining() override;
    void writeByte(int8_t v) /* throws(IOException) */ override;
    void writeChar(char16_t v) /* throws(IOException) */ override;
    void writeShort(int16_t v) /* throws(IOException) */ override;

    // Generated
    FileOutputBuffer(::java::io::File* f, bool append);
    FileOutputBuffer(::java::io::File* f);
    FileOutputBuffer(::java::lang::String* fileName);
protected:
    FileOutputBuffer(const ::default_init_tag&);


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
    void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
