// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/util/NavigableSet.hpp>

struct default_init_tag;

class java::util::TreeMap_KeySet final
    : public AbstractSet
    , public NavigableSet
{

public:
    typedef AbstractSet super;

private:
    NavigableMap* m {  };

protected:
    void ctor(NavigableMap* arg0);

public:
    ::java::lang::Object* ceiling(::java::lang::Object* arg0) override;
    void clear() override;
    Comparator* comparator() override;
    bool contains(::java::lang::Object* arg0) override;
    Iterator* descendingIterator() override;
    NavigableSet* descendingSet() override;
    ::java::lang::Object* first() override;
    ::java::lang::Object* floor(::java::lang::Object* arg0) override;
    SortedSet* headSet(::java::lang::Object* arg0) override;
    NavigableSet* headSet(::java::lang::Object* arg0, bool arg1) override;
    ::java::lang::Object* higher(::java::lang::Object* arg0) override;
    bool isEmpty() override;
    Iterator* iterator() override;
    ::java::lang::Object* last() override;
    ::java::lang::Object* lower(::java::lang::Object* arg0) override;
    ::java::lang::Object* pollFirst() override;
    ::java::lang::Object* pollLast() override;
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    NavigableSet* subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    SortedSet* tailSet(::java::lang::Object* arg0) override;
    NavigableSet* tailSet(::java::lang::Object* arg0, bool arg1) override;

    // Generated

public: /* package */
    TreeMap_KeySet(NavigableMap* arg0);
protected:
    TreeMap_KeySet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0);
    bool addAll(Collection* arg0);
    bool containsAll(Collection* arg0);
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
