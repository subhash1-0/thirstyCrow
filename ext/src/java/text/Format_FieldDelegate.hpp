// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/text/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::text::Format_FieldDelegate
    : public virtual ::java::lang::Object
{

    virtual void formatted(Format_Field* arg0, ::java::lang::Object* arg1, int32_t arg2, int32_t arg3, ::java::lang::StringBuffer* arg4) = 0;
    virtual void formatted(int32_t arg0, Format_Field* arg1, ::java::lang::Object* arg2, int32_t arg3, int32_t arg4, ::java::lang::StringBuffer* arg5) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
