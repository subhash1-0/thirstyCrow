// Generated from /pastry-2.1/src/rice/p2p/util/RandomAccessFileIOBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/RandomAccessFile.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::RandomAccessFileIOBuffer
    : public ::java::io::RandomAccessFile
    , public virtual ::rice::p2p::commonapi::rawserialization::InputBuffer
    , public virtual ::rice::p2p::commonapi::rawserialization::OutputBuffer
{

public:
    typedef ::java::io::RandomAccessFile super;
protected:
    void ctor(::java::io::File* file, ::java::lang::String* mode) /* throws(FileNotFoundException) */;
    void ctor(::java::lang::String* name, ::java::lang::String* mode) /* throws(FileNotFoundException) */;

public:
    int32_t bytesRemaining() override;
    void writeByte(int8_t v) /* throws(IOException) */ override;
    void writeChar(char16_t v) /* throws(IOException) */ override;
    void writeShort(int16_t v) /* throws(IOException) */ override;

    // Generated
    RandomAccessFileIOBuffer(::java::io::File* file, ::java::lang::String* mode);
    RandomAccessFileIOBuffer(::java::lang::String* name, ::java::lang::String* mode);
protected:
    RandomAccessFileIOBuffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t read(::int8_tArray* b);
    virtual int32_t read(::int8_tArray* b, int32_t off, int32_t len);
    virtual bool readBoolean();
    virtual int8_t readByte();
    virtual char16_t readChar();
    virtual double readDouble();
    virtual float readFloat();
    virtual int32_t readInt();
    virtual int64_t readLong();
    virtual int16_t readShort();
    virtual ::java::lang::String* readUTF();
    virtual void write(::int8_tArray* b, int32_t off, int32_t len);
    virtual void writeBoolean(bool v);
    virtual void writeDouble(double v);
    virtual void writeFloat(float v);
    virtual void writeInt(int32_t v);
    virtual void writeLong(int64_t v);
    virtual void writeUTF(::java::lang::String* str);
    virtual int32_t read();
    void write(int32_t arg0);
    void write(::int8_tArray* arg0);
    void writeByte(int32_t arg0);
    void writeChar(int32_t arg0);
    void writeShort(int32_t arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
