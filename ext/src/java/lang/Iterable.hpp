// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::lang::Iterable
    : public virtual Object
{

    virtual void forEach(::java::util::function::Consumer* arg0);
    virtual ::java::util::Iterator* iterator() = 0;
    virtual ::java::util::Spliterator* spliterator();

    // Generated
    static ::java::lang::Class *class_();
};
