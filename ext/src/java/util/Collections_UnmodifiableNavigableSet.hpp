// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableSortedSet.hpp>
#include <java/util/NavigableSet.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableNavigableSet
    : public Collections_UnmodifiableSortedSet
    , public virtual NavigableSet
    , public virtual ::java::io::Serializable
{

public:
    typedef Collections_UnmodifiableSortedSet super;

private:
    static NavigableSet* EMPTY_NAVIGABLE_SET_;
    NavigableSet* ns {  };
    static constexpr int64_t serialVersionUID { int64_t(-6027448201786391929LL) };

protected:
    void ctor(NavigableSet* arg0);

public:
    ::java::lang::Object* ceiling(::java::lang::Object* arg0) override;
    Iterator* descendingIterator() override;
    NavigableSet* descendingSet() override;
    ::java::lang::Object* floor(::java::lang::Object* arg0) override;
    NavigableSet* headSet(::java::lang::Object* arg0, bool arg1) override;
    ::java::lang::Object* higher(::java::lang::Object* arg0) override;
    ::java::lang::Object* lower(::java::lang::Object* arg0) override;
    ::java::lang::Object* pollFirst() override;
    ::java::lang::Object* pollLast() override;
    NavigableSet* subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    NavigableSet* tailSet(::java::lang::Object* arg0, bool arg1) override;

    // Generated

public: /* package */
    Collections_UnmodifiableNavigableSet(NavigableSet* arg0);
protected:
    Collections_UnmodifiableNavigableSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEach(::java::util::function::Consumer* arg0);
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool removeIf(::java::util::function::Predicate* arg0);
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
    virtual SortedSet* headSet(::java::lang::Object* arg0);
    virtual ::java::lang::Object* last();
    Spliterator* spliterator();
    virtual SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual SortedSet* tailSet(::java::lang::Object* arg0);

private:
    static NavigableSet*& EMPTY_NAVIGABLE_SET();
    virtual ::java::lang::Class* getClass0();
};
