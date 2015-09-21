// Generated from /pastry-2.1/src/rice/p2p/util/SortedLinkedList.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/LinkedList.hpp>

struct default_init_tag;

class rice::p2p::util::SortedLinkedList
    : public ::java::util::LinkedList
{

public:
    typedef ::java::util::LinkedList super;
    bool addAll(::java::util::Collection* c) override;
    bool addAll(int32_t index, ::java::util::Collection* c) override;
    virtual void addFirst(::java::lang::Comparable* o);
    virtual void addLast(::java::lang::Comparable* o);
    ::java::util::ListIterator* listIterator(int32_t index) override;
    virtual ::java::lang::Comparable* set(int32_t index, ::java::lang::Comparable* element);
    virtual bool add(::java::lang::Comparable* o);

    // Generated
    SortedLinkedList();
protected:
    SortedLinkedList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0) override;
    void addFirst(::java::lang::Object* arg0) override;
    void addLast(::java::lang::Object* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    void add(int32_t arg0, ::java::lang::Object* arg1);
    ::java::util::ListIterator* listIterator();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SortedLinkedList_listIterator_1;
};
