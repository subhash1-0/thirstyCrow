// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/InputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::rawserialization::InputBuffer
    : public virtual ::java::lang::Object
{
    static constexpr int32_t UNKNOWN { int32_t(-2) };
    virtual int32_t read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */ = 0;
    virtual int32_t read(::int8_tArray* b) /* throws(IOException) */ = 0;
    virtual bool readBoolean() /* throws(IOException) */ = 0;
    virtual int8_t readByte() /* throws(IOException) */ = 0;
    virtual char16_t readChar() /* throws(IOException) */ = 0;
    virtual double readDouble() /* throws(IOException) */ = 0;
    virtual float readFloat() /* throws(IOException) */ = 0;
    virtual int32_t readInt() /* throws(IOException) */ = 0;
    virtual int64_t readLong() /* throws(IOException) */ = 0;
    virtual int16_t readShort() /* throws(IOException) */ = 0;
    virtual ::java::lang::String* readUTF() /* throws(IOException) */ = 0;
    virtual int32_t bytesRemaining() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
