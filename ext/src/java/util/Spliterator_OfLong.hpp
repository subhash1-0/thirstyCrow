// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Spliterator_OfPrimitive.hpp>

struct java::util::Spliterator_OfLong
    : public virtual Spliterator_OfPrimitive
{

    virtual void forEachRemaining(::java::util::function::LongConsumer* arg0);
    /*void forEachRemaining(::java::util::function::Consumer* arg0); (already declared) */
    virtual bool tryAdvance(::java::util::function::LongConsumer* arg0) = 0;
    /*bool tryAdvance(::java::util::function::Consumer* arg0); (already declared) */
    Spliterator_OfLong* trySplit() = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    virtual bool tryAdvance(::java::util::function::Consumer* arg0) = 0;
};
