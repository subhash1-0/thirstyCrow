// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/SortedSet.hpp>

struct java::util::NavigableSet
    : public virtual SortedSet
{

    virtual ::java::lang::Object* ceiling(::java::lang::Object* arg0) = 0;
    virtual Iterator* descendingIterator() = 0;
    virtual NavigableSet* descendingSet() = 0;
    virtual ::java::lang::Object* floor(::java::lang::Object* arg0) = 0;
    /*SortedSet* headSet(::java::lang::Object* arg0); (already declared) */
    virtual NavigableSet* headSet(::java::lang::Object* arg0, bool arg1) = 0;
    virtual ::java::lang::Object* higher(::java::lang::Object* arg0) = 0;
    /*Iterator* iterator(); (already declared) */
    virtual ::java::lang::Object* lower(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* pollFirst() = 0;
    virtual ::java::lang::Object* pollLast() = 0;
    /*SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1); (already declared) */
    virtual NavigableSet* subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) = 0;
    /*SortedSet* tailSet(::java::lang::Object* arg0); (already declared) */
    virtual NavigableSet* tailSet(::java::lang::Object* arg0, bool arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual SortedSet* headSet(::java::lang::Object* arg0) = 0;
    virtual SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    virtual SortedSet* tailSet(::java::lang::Object* arg0) = 0;
};
