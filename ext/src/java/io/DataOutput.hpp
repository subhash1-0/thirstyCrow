// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::io::DataOutput
    : public virtual ::java::lang::Object
{

    virtual void write(int32_t arg0) = 0;
    virtual void write(::int8_tArray* arg0) = 0;
    virtual void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual void writeBoolean(bool arg0) = 0;
    virtual void writeByte(int32_t arg0) = 0;
    virtual void writeBytes(::java::lang::String* arg0) = 0;
    virtual void writeChar(int32_t arg0) = 0;
    virtual void writeChars(::java::lang::String* arg0) = 0;
    virtual void writeDouble(double arg0) = 0;
    virtual void writeFloat(float arg0) = 0;
    virtual void writeInt(int32_t arg0) = 0;
    virtual void writeLong(int64_t arg0) = 0;
    virtual void writeShort(int32_t arg0) = 0;
    virtual void writeUTF(::java::lang::String* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
