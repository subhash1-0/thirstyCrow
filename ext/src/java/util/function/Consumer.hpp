// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::function::Consumer
    : public virtual ::java::lang::Object
{

    virtual void accept(::java::lang::Object* arg0) = 0;
    virtual Consumer* andThen(Consumer* arg0);

    // Generated
    static ::java::lang::Class *class_();
};
