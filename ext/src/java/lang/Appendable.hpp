// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::lang::Appendable
    : public virtual Object
{

    virtual Appendable* append(CharSequence* arg0) = 0;
    virtual Appendable* append(char16_t arg0) = 0;
    virtual Appendable* append(CharSequence* arg0, int32_t arg1, int32_t arg2) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
