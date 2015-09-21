// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Collection.hpp>

struct java::util::List
    : public virtual Collection
{

    /*bool add(::java::lang::Object* arg0); (already declared) */
    virtual void add(int32_t arg0, ::java::lang::Object* arg1) = 0;
    /*bool addAll(Collection* arg0); (already declared) */
    virtual bool addAll(int32_t arg0, Collection* arg1) = 0;
    /*void clear(); (already declared) */
    /*bool contains(::java::lang::Object* arg0); (already declared) */
    /*bool containsAll(Collection* arg0); (already declared) */
    /*bool equals(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* get(int32_t arg0) = 0;
    /*int32_t hashCode(); (already declared) */
    virtual int32_t indexOf(::java::lang::Object* arg0) = 0;
    /*bool isEmpty(); (already declared) */
    /*Iterator* iterator(); (already declared) */
    virtual int32_t lastIndexOf(::java::lang::Object* arg0) = 0;
    virtual ListIterator* listIterator() = 0;
    virtual ListIterator* listIterator(int32_t arg0) = 0;
    /*bool remove(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* remove(int32_t arg0) = 0;
    /*bool removeAll(Collection* arg0); (already declared) */
    virtual void replaceAll(::java::util::function::UnaryOperator* arg0);
    /*bool retainAll(Collection* arg0); (already declared) */
    virtual ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) = 0;
    /*int32_t size(); (already declared) */
    virtual void sort(Comparator* arg0);
    /*Spliterator* spliterator(); (already declared) */
    virtual List* subList(int32_t arg0, int32_t arg1) = 0;
    /*::java::lang::ObjectArray* toArray_(); (already declared) */
    /*::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
    virtual bool add(::java::lang::Object* arg0) = 0;
    virtual bool addAll(Collection* arg0) = 0;
    virtual bool remove(::java::lang::Object* arg0) = 0;
};
