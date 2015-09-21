// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/OutputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::rawserialization::OutputBuffer
    : public virtual ::java::lang::Object
{
    virtual void write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ = 0;
    virtual void writeBoolean(bool v) /* throws(IOException) */ = 0;
    virtual void writeByte(int8_t v) /* throws(IOException) */ = 0;
    virtual void writeChar(char16_t v) /* throws(IOException) */ = 0;
    virtual void writeDouble(double v) /* throws(IOException) */ = 0;
    virtual void writeFloat(float v) /* throws(IOException) */ = 0;
    virtual void writeInt(int32_t v) /* throws(IOException) */ = 0;
    virtual void writeLong(int64_t v) /* throws(IOException) */ = 0;
    virtual void writeShort(int16_t v) /* throws(IOException) */ = 0;
    virtual void writeUTF(::java::lang::String* str) /* throws(IOException) */ = 0;
    virtual int32_t bytesRemaining() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
