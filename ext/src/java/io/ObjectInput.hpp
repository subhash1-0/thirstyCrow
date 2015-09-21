// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/DataInput.hpp>
#include <java/lang/AutoCloseable.hpp>

struct java::io::ObjectInput
    : public virtual DataInput
    , public virtual ::java::lang::AutoCloseable
{

    virtual int32_t available() = 0;
    /*void close(); (already declared) */
    virtual int32_t read() = 0;
    virtual int32_t read(::int8_tArray* arg0) = 0;
    virtual int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual ::java::lang::Object* readObject() = 0;
    virtual int64_t skip(int64_t arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
