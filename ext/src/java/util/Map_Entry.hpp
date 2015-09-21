// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Map_Entry
    : public virtual ::java::lang::Object
{

    static Comparator* comparingByKey();
    static Comparator* comparingByKey(Comparator* arg0);
    static Comparator* comparingByValue();
    static Comparator* comparingByValue(Comparator* arg0);
    /*virtual bool equals(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* getKey() = 0;
    virtual ::java::lang::Object* getValue() = 0;
    /*virtual int32_t hashCode(); (already declared) */
    virtual ::java::lang::Object* setValue(::java::lang::Object* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
