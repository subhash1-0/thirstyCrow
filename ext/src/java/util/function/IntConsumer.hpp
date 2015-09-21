// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::function::IntConsumer
    : public virtual ::java::lang::Object
{

    virtual void accept(int32_t arg0) = 0;
    virtual IntConsumer* andThen(IntConsumer* arg0);

    // Generated
    static ::java::lang::Class *class_();
};
