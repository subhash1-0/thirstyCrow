// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::function::LongConsumer
    : public virtual ::java::lang::Object
{

    virtual void accept(int64_t arg0) = 0;
    virtual LongConsumer* andThen(LongConsumer* arg0);

    // Generated
    static ::java::lang::Class *class_();
};
