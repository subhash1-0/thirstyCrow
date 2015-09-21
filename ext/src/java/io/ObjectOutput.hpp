// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/DataOutput.hpp>
#include <java/lang/AutoCloseable.hpp>

struct java::io::ObjectOutput
    : public virtual DataOutput
    , public virtual ::java::lang::AutoCloseable
{

    /*void close(); (already declared) */
    virtual void flush() = 0;
    /*void write(int32_t arg0); (already declared) */
    /*void write(::int8_tArray* arg0); (already declared) */
    /*void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (already declared) */
    virtual void writeObject(::java::lang::Object* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
