// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SimpleInputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/DataInputStream.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>

struct default_init_tag;

class rice::p2p::util::rawserialization::SimpleInputBuffer
    : public ::java::io::DataInputStream
    , public virtual ::rice::p2p::commonapi::rawserialization::InputBuffer
{

public:
    typedef ::java::io::DataInputStream super;

public: /* package */
    ::java::io::ByteArrayInputStream* bais {  };
protected:
    void ctor(::java::nio::ByteBuffer* bb);
    void ctor(::int8_tArray* bytes);
    void ctor(::int8_tArray* bytes, int32_t offset);
    void ctor(::int8_tArray* bytes, int32_t offset, int32_t length);

public:
    int32_t bytesRemaining() override;

    // Generated
    SimpleInputBuffer(::java::nio::ByteBuffer* bb);
    SimpleInputBuffer(::int8_tArray* bytes);
    SimpleInputBuffer(::int8_tArray* bytes, int32_t offset);
    SimpleInputBuffer(::int8_tArray* bytes, int32_t offset, int32_t length);
protected:
    SimpleInputBuffer(const ::default_init_tag&);


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
    static ::java::lang::String* readUTF(::java::io::DataInput* arg0);
    int32_t read();

private:
    virtual ::java::lang::Class* getClass0();
};
