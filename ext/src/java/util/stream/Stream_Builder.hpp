// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/function/Consumer.hpp>

struct java::util::stream::Stream_Builder
    : public virtual ::java::util::function::Consumer
{

    /*void accept(::java::lang::Object* arg0); (already declared) */
    virtual Stream_Builder* add(::java::lang::Object* arg0);
    virtual Stream* build() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
