// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedCollection.hpp>
#include <java/util/List.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedList
    : public Collections_SynchronizedCollection
    , public virtual List
{

public:
    typedef Collections_SynchronizedCollection super;

public: /* package */
    List* list {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(-7754090372962971524LL) };

protected:
    void ctor(List* arg0);
    void ctor(List* arg0, ::java::lang::Object* arg1);

public:
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    int32_t hashCode() override;
    int32_t indexOf(::java::lang::Object* arg0) override;
    int32_t lastIndexOf(::java::lang::Object* arg0) override;
    ListIterator* listIterator() override;
    ListIterator* listIterator(int32_t arg0) override;
    /*::java::lang::Object* readResolve(); (private) */
    ::java::lang::Object* remove(int32_t arg0) override;
    void replaceAll(::java::util::function::UnaryOperator* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    void sort(Comparator* arg0) override;
    List* subList(int32_t arg0, int32_t arg1) override;

    // Generated

public: /* package */
    Collections_SynchronizedList(List* arg0);
    Collections_SynchronizedList(List* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEach(::java::util::function::Consumer* action);
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool removeIf(::java::util::function::Predicate* filter);
    virtual ::java::util::stream::Stream* stream();
    bool add(::java::lang::Object* arg0);
    bool addAll(Collection* arg0);
    void clear();
    bool contains(::java::lang::Object* arg0);
    bool containsAll(Collection* arg0);
    bool isEmpty();
    Iterator* iterator();
    bool remove(::java::lang::Object* arg0);
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    int32_t size();
    Spliterator* spliterator();
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
