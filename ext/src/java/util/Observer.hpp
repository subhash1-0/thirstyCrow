// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Observer
    : public virtual ::java::lang::Object
{

    virtual void update(Observable* arg0, ::java::lang::Object* arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
