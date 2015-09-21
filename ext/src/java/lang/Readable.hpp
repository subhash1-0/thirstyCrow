// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::lang::Readable
    : public virtual Object
{

    virtual int32_t read(::java::nio::CharBuffer* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
