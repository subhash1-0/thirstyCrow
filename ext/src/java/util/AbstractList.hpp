// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractCollection.hpp>
#include <java/util/List.hpp>

struct default_init_tag;

class java::util::AbstractList
    : public AbstractCollection
    , public virtual List
{

public:
    typedef AbstractCollection super;

public: /* protected */
    int32_t modCount {  };

protected:
    void ctor();

public:
    bool add(::java::lang::Object* arg0) override;
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    void clear() override;
    bool equals(::java::lang::Object* arg0) override;
    /*::java::lang::Object* get(int32_t arg0); (already declared) */
    int32_t hashCode() override;
    int32_t indexOf(::java::lang::Object* arg0) override;
    Iterator* iterator() override;
    int32_t lastIndexOf(::java::lang::Object* arg0) override;
    ListIterator* listIterator() override;
    ListIterator* listIterator(int32_t arg0) override;
    /*::java::lang::String* outOfBoundsMsg(int32_t arg0); (private) */
    /*void rangeCheckForAdd(int32_t arg0); (private) */
    ::java::lang::Object* remove(int32_t arg0) override;

public: /* protected */
    virtual void removeRange(int32_t arg0, int32_t arg1);

public:
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    List* subList(int32_t arg0, int32_t arg1) override;

    // Generated

public: /* protected */
    AbstractList();
protected:
    AbstractList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool addAll(Collection* arg0);
    bool contains(::java::lang::Object* arg0);
    bool containsAll(Collection* arg0);
    bool isEmpty();
    bool remove(::java::lang::Object* arg0);
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
