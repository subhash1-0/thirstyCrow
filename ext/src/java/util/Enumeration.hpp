// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Enumeration
    : public virtual ::java::lang::Object
{

    virtual bool hasMoreElements() = 0;
    virtual ::java::lang::Object* nextElement() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
