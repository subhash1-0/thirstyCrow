// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Iterator
    : public virtual ::java::lang::Object
{

    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    virtual bool hasNext() = 0;
    virtual ::java::lang::Object* next() = 0;
    virtual void remove();

    // Generated
    static ::java::lang::Class *class_();
};
