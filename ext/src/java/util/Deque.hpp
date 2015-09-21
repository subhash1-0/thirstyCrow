// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Queue.hpp>

struct java::util::Deque
    : public virtual Queue
{

    /*bool add(::java::lang::Object* arg0); (already declared) */
    virtual void addFirst(::java::lang::Object* arg0) = 0;
    virtual void addLast(::java::lang::Object* arg0) = 0;
    /*bool contains(::java::lang::Object* arg0); (already declared) */
    virtual Iterator* descendingIterator() = 0;
    /*::java::lang::Object* element(); (already declared) */
    virtual ::java::lang::Object* getFirst() = 0;
    virtual ::java::lang::Object* getLast() = 0;
    /*Iterator* iterator(); (already declared) */
    /*bool offer(::java::lang::Object* arg0); (already declared) */
    virtual bool offerFirst(::java::lang::Object* arg0) = 0;
    virtual bool offerLast(::java::lang::Object* arg0) = 0;
    /*::java::lang::Object* peek(); (already declared) */
    virtual ::java::lang::Object* peekFirst() = 0;
    virtual ::java::lang::Object* peekLast() = 0;
    /*::java::lang::Object* poll(); (already declared) */
    virtual ::java::lang::Object* pollFirst() = 0;
    virtual ::java::lang::Object* pollLast() = 0;
    virtual ::java::lang::Object* pop() = 0;
    virtual void push(::java::lang::Object* arg0) = 0;
    /*::java::lang::Object* remove(); (already declared) */
    /*bool remove(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::Object* removeFirst() = 0;
    virtual bool removeFirstOccurrence(::java::lang::Object* arg0) = 0;
    virtual ::java::lang::Object* removeLast() = 0;
    virtual bool removeLastOccurrence(::java::lang::Object* arg0) = 0;
    /*int32_t size(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
