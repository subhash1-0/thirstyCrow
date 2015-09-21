// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedSortedSet.hpp>
#include <java/util/NavigableSet.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedNavigableSet
    : public Collections_SynchronizedSortedSet
    , public virtual NavigableSet
{

public:
    typedef Collections_SynchronizedSortedSet super;

private:
    NavigableSet* ns {  };
    static constexpr int64_t serialVersionUID { int64_t(-5505529816273629798LL) };

protected:
    void ctor(NavigableSet* arg0);
    void ctor(NavigableSet* arg0, ::java::lang::Object* arg1);

public:
    ::java::lang::Object* ceiling(::java::lang::Object* arg0) override;
    Iterator* descendingIterator() override;
    NavigableSet* descendingSet() override;
    ::java::lang::Object* floor(::java::lang::Object* arg0) override;
    NavigableSet* headSet(::java::lang::Object* arg0) override;
    NavigableSet* headSet(::java::lang::Object* arg0, bool arg1) override;
    ::java::lang::Object* higher(::java::lang::Object* arg0) override;
    ::java::lang::Object* lower(::java::lang::Object* arg0) override;
    ::java::lang::Object* pollFirst() override;
    ::java::lang::Object* pollLast() override;
    NavigableSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    NavigableSet* subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    NavigableSet* tailSet(::java::lang::Object* arg0) override;
    NavigableSet* tailSet(::java::lang::Object* arg0, bool arg1) override;

    // Generated

public: /* package */
    Collections_SynchronizedNavigableSet(NavigableSet* arg0);
    Collections_SynchronizedNavigableSet(NavigableSet* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedNavigableSet(const ::default_init_tag&);


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
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();
    bool isEmpty();
    Iterator* iterator();
    bool remove(::java::lang::Object* arg0);
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    int32_t size();
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);
    virtual Comparator* comparator();
    virtual ::java::lang::Object* first();
    virtual ::java::lang::Object* last();
    Spliterator* spliterator();

private:
    virtual ::java::lang::Class* getClass0();
};
