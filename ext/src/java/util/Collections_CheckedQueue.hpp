// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_CheckedCollection.hpp>
#include <java/util/Queue.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_CheckedQueue
    : public Collections_CheckedCollection
    , public virtual Queue
    , public virtual ::java::io::Serializable
{

public:
    typedef Collections_CheckedCollection super;

public: /* package */
    Queue* queue {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(1433151992604707767LL) };

protected:
    void ctor(Queue* arg0, ::java::lang::Class* arg1);

public:
    ::java::lang::Object* element() override;
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    bool offer(::java::lang::Object* arg0) override;
    ::java::lang::Object* peek() override;
    ::java::lang::Object* poll() override;
    ::java::lang::Object* remove() override;

    // Generated

public: /* package */
    Collections_CheckedQueue(Queue* arg0, ::java::lang::Class* arg1);
protected:
    Collections_CheckedQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEach(::java::util::function::Consumer* arg0);
    virtual bool addAll(Collection* arg0);
    virtual void clear();
    virtual bool contains(::java::lang::Object* arg0);
    virtual bool containsAll(Collection* arg0);
    virtual bool isEmpty();
    Iterator* iterator();
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool remove(::java::lang::Object* arg0);
    virtual bool removeAll(Collection* arg0);
    virtual bool removeIf(::java::util::function::Predicate* arg0);
    virtual bool retainAll(Collection* arg0);
    virtual int32_t size();
    Spliterator* spliterator();
    virtual ::java::util::stream::Stream* stream();
    virtual ::java::lang::ObjectArray* toArray_();
    virtual ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);
    bool add(::java::lang::Object* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
