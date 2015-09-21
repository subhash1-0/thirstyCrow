// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/AutoCloseable.hpp>

struct java::util::stream::BaseStream
    : public virtual ::java::lang::AutoCloseable
{

    /*void close(); (already declared) */
    virtual bool isParallel() = 0;
    virtual ::java::util::Iterator* iterator() = 0;
    virtual BaseStream* onClose(::java::lang::Runnable* arg0) = 0;
    virtual BaseStream* parallel() = 0;
    virtual BaseStream* sequential() = 0;
    virtual ::java::util::Spliterator* spliterator() = 0;
    virtual BaseStream* unordered() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
