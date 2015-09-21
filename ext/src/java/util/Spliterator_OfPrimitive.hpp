// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Spliterator.hpp>

struct java::util::Spliterator_OfPrimitive
    : public virtual Spliterator
{

    virtual void forEachRemaining(::java::lang::Object* arg0);
    virtual bool tryAdvance(::java::lang::Object* arg0) = 0;
    Spliterator_OfPrimitive* trySplit() = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    virtual bool tryAdvance(::java::util::function::Consumer* arg0) = 0;
};
