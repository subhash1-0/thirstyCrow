// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Set.hpp>

struct java::util::SortedSet
    : public virtual Set
{

    virtual Comparator* comparator() = 0;
    virtual ::java::lang::Object* first() = 0;
    virtual SortedSet* headSet(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* last() = 0;
    /*Spliterator* spliterator(); (already declared) */
    virtual SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    virtual SortedSet* tailSet(::java::lang::Object* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
