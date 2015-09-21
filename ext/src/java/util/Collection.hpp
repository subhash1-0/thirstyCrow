// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Iterable.hpp>

struct java::util::Collection
    : public virtual ::java::lang::Iterable
{

    virtual bool add(::java::lang::Object* arg0) = 0;
    virtual bool addAll(Collection* arg0) = 0;
    virtual void clear() = 0;
    virtual bool contains(::java::lang::Object* arg0) = 0;
    virtual bool containsAll(Collection* arg0) = 0;
    /*virtual bool equals(::java::lang::Object* arg0); (already declared) */
    /*virtual int32_t hashCode(); (already declared) */
    virtual bool isEmpty() = 0;
    /*Iterator* iterator(); (already declared) */
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool remove(::java::lang::Object* arg0) = 0;
    virtual bool removeAll(Collection* arg0) = 0;
    virtual bool removeIf(::java::util::function::Predicate* arg0);
    virtual bool retainAll(Collection* arg0) = 0;
    virtual int32_t size() = 0;
    /*Spliterator* spliterator(); (already declared) */
    virtual ::java::util::stream::Stream* stream();
    virtual ::java::lang::ObjectArray* toArray_() = 0;
    virtual ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
