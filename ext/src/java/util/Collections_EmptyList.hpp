// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>
#include <java/util/RandomAccess.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_EmptyList
    : public AbstractList
    , public virtual RandomAccess
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractList super;

private:
    static constexpr int64_t serialVersionUID { int64_t(8842843931221139166LL) };

    /*void ctor(); (private) */

public:
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    bool equals(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Iterator* iterator() override;
    ListIterator* listIterator() override;
    /*::java::lang::Object* readResolve(); (private) */
    bool removeIf(::java::util::function::Predicate* arg0) override;
    void replaceAll(::java::util::function::UnaryOperator* arg0) override;
    int32_t size() override;
    void sort(Comparator* arg0) override;
    Spliterator* spliterator() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

    // Generated
    Collections_EmptyList();
protected:
    Collections_EmptyList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ListIterator* listIterator(int32_t arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
