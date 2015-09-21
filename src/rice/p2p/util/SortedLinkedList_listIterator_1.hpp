// Generated from /pastry-2.1/src/rice/p2p/util/SortedLinkedList.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ListIterator.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::p2p::util::SortedLinkedList_listIterator_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::ListIterator
{

public:
    typedef ::java::lang::Object super;
    virtual void add(::java::lang::Comparable* o);
    bool hasNext() override;
    bool hasPrevious() override;
    ::java::lang::Comparable* next() override;
    int32_t nextIndex() override;
    ::java::lang::Comparable* previous() override;
    int32_t previousIndex() override;
    void remove() override;
    virtual void set(::java::lang::Comparable* o);

    // Generated
    SortedLinkedList_listIterator_1(SortedLinkedList *SortedLinkedList_this, ::java::util::ListIterator* it);
    static ::java::lang::Class *class_();
    virtual void add(::java::lang::Object* arg0) override;
    virtual void set(::java::lang::Object* arg0) override;
    SortedLinkedList *SortedLinkedList_this;
    ::java::util::ListIterator* it;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SortedLinkedList;
};
