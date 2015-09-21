// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/util/NavigableSet.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::TreeSet
    : public AbstractSet
    , public virtual NavigableSet
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSet super;

private:
    static ::java::lang::Object* PRESENT_;
    NavigableMap* m {  };
    static constexpr int64_t serialVersionUID { int64_t(-2479143000061671589LL) };

protected:
    void ctor();
    void ctor(NavigableMap* arg0);
    void ctor(Comparator* arg0);
    void ctor(Collection* arg0);
    void ctor(SortedSet* arg0);

public:
    bool add(::java::lang::Object* arg0) override;
    bool addAll(Collection* arg0) override;
    ::java::lang::Object* ceiling(::java::lang::Object* arg0) override;
    void clear() override;
    ::java::lang::Object* clone() override;
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
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    NavigableSet* subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    SortedSet* tailSet(::java::lang::Object* arg0) override;
    NavigableSet* tailSet(::java::lang::Object* arg0, bool arg1) override;
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    TreeSet();

public: /* package */
    TreeSet(NavigableMap* arg0);

public:
    TreeSet(Comparator* arg0);
    TreeSet(Collection* arg0);
    TreeSet(SortedSet* arg0);
protected:
    TreeSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool containsAll(Collection* arg0);
    bool equals(::java::lang::Object* arg0);
    int32_t hashCode();
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    static ::java::lang::Object*& PRESENT();
    virtual ::java::lang::Class* getClass0();
};
