// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/util/Queue.hpp>

struct java::util::concurrent::BlockingQueue
    : public virtual ::java::util::Queue
{

    /*bool add(::java::lang::Object* arg0); (already declared) */
    /*bool contains(::java::lang::Object* arg0); (already declared) */
    virtual int32_t drainTo(::java::util::Collection* arg0) = 0;
    virtual int32_t drainTo(::java::util::Collection* arg0, int32_t arg1) = 0;
    /*bool offer(::java::lang::Object* arg0); (already declared) */
    virtual bool offer(::java::lang::Object* arg0, int64_t arg1, TimeUnit* arg2) = 0;
    virtual ::java::lang::Object* poll(int64_t arg0, TimeUnit* arg1) = 0;
    virtual void put(::java::lang::Object* arg0) = 0;
    virtual int32_t remainingCapacity() = 0;
    /*bool remove(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* take() = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual bool offer(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* poll() = 0;
};
