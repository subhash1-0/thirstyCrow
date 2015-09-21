// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Iterator.hpp>

struct java::util::ListIterator
    : public virtual Iterator
{

    virtual void add(::java::lang::Object* arg0) = 0;
    /*bool hasNext(); (already declared) */
    virtual bool hasPrevious() = 0;
    /*::java::lang::Object* next(); (already declared) */
    virtual int32_t nextIndex() = 0;
    virtual ::java::lang::Object* previous() = 0;
    virtual int32_t previousIndex() = 0;
    /*void remove(); (already declared) */
    virtual void set(::java::lang::Object* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
