// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::lang::CharSequence
    : public virtual Object
{

    virtual char16_t charAt(int32_t arg0) = 0;
    virtual ::java::util::stream::IntStream* chars();
    virtual ::java::util::stream::IntStream* codePoints();
    virtual int32_t length() = 0;
    virtual CharSequence* subSequence(int32_t arg0, int32_t arg1) = 0;
    /*virtual String* toString(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
