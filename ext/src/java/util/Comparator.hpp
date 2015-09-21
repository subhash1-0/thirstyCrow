// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Comparator
    : public virtual ::java::lang::Object
{

    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    static Comparator* comparing(::java::util::function::Function* arg0);
    static Comparator* comparing(::java::util::function::Function* arg0, Comparator* arg1);
    static Comparator* comparingDouble(::java::util::function::ToDoubleFunction* arg0);
    static Comparator* comparingInt(::java::util::function::ToIntFunction* arg0);
    static Comparator* comparingLong(::java::util::function::ToLongFunction* arg0);
    /*virtual bool equals(::java::lang::Object* arg0); (already declared) */
    static Comparator* naturalOrder();
    static Comparator* nullsFirst(Comparator* arg0);
    static Comparator* nullsLast(Comparator* arg0);
    static Comparator* reverseOrder();
    virtual Comparator* reversed();
    virtual Comparator* thenComparing(Comparator* arg0);
    virtual Comparator* thenComparing(::java::util::function::Function* arg0);
    virtual Comparator* thenComparing(::java::util::function::Function* arg0, Comparator* arg1);
    virtual Comparator* thenComparingDouble(::java::util::function::ToDoubleFunction* arg0);
    virtual Comparator* thenComparingInt(::java::util::function::ToIntFunction* arg0);
    virtual Comparator* thenComparingLong(::java::util::function::ToLongFunction* arg0);

    // Generated
    static ::java::lang::Class *class_();
};
