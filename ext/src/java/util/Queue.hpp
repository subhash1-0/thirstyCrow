// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Collection.hpp>

struct java::util::Queue
    : public virtual Collection
{

    /*bool add(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* element() = 0;
    virtual bool offer(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* peek() = 0;
    virtual ::java::lang::Object* poll() = 0;
    virtual ::java::lang::Object* remove() = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual bool remove(::java::lang::Object* arg0) = 0;
};
