// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableSet.hpp>
#include <java/util/SortedSet.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableSortedSet
    : public Collections_UnmodifiableSet
    , public virtual SortedSet
    , public virtual ::java::io::Serializable
{

public:
    typedef Collections_UnmodifiableSet super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-4929149591599911165LL) };
    SortedSet* ss {  };

protected:
    void ctor(SortedSet* arg0);

public:
    Comparator* comparator() override;
    ::java::lang::Object* first() override;
    SortedSet* headSet(::java::lang::Object* arg0) override;
    ::java::lang::Object* last() override;
    SortedSet* subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    SortedSet* tailSet(::java::lang::Object* arg0) override;

    // Generated

public: /* package */
    Collections_UnmodifiableSortedSet(SortedSet* arg0);
protected:
    Collections_UnmodifiableSortedSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEach(::java::util::function::Consumer* action);
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool removeIf(::java::util::function::Predicate* filter);
    virtual ::java::util::stream::Stream* stream();
    bool add(::java::lang::Object* e);
    bool addAll(Collection* c);
    void clear();
    bool contains(::java::lang::Object* o);
    bool containsAll(Collection* c);
    bool equals(::java::lang::Object* o);
    int32_t hashCode();
    bool isEmpty();
    Iterator* iterator();
    bool remove(::java::lang::Object* o);
    bool removeAll(Collection* c);
    bool retainAll(Collection* c);
    int32_t size();
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* a);
    Spliterator* spliterator();

private:
    virtual ::java::lang::Class* getClass0();
};
