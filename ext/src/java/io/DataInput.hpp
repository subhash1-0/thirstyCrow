// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::io::DataInput
    : public virtual ::java::lang::Object
{

    virtual bool readBoolean() = 0;
    virtual int8_t readByte() = 0;
    virtual char16_t readChar() = 0;
    virtual double readDouble() = 0;
    virtual float readFloat() = 0;
    virtual void readFully(::int8_tArray* arg0) = 0;
    virtual void readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual int32_t readInt() = 0;
    virtual ::java::lang::String* readLine() = 0;
    virtual int64_t readLong() = 0;
    virtual int16_t readShort() = 0;
    virtual ::java::lang::String* readUTF() = 0;
    virtual int32_t readUnsignedByte() = 0;
    virtual int32_t readUnsignedShort() = 0;
    virtual int32_t skipBytes(int32_t arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
