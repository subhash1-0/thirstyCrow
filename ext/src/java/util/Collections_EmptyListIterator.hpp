// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Collections_EmptyIterator.hpp>
#include <java/util/ListIterator.hpp>

struct default_init_tag;

class java::util::Collections_EmptyListIterator
    : public Collections_EmptyIterator
    , public virtual ListIterator
{

public:
    typedef Collections_EmptyIterator super;

private:
    static Collections_EmptyListIterator* EMPTY_ITERATOR_;

    /*void ctor(); (private) */

public:
    void add(::java::lang::Object* arg0) override;
    bool hasPrevious() override;
    int32_t nextIndex() override;
    ::java::lang::Object* previous() override;
    int32_t previousIndex() override;
    void set(::java::lang::Object* arg0) override;

    // Generated
    Collections_EmptyListIterator();
protected:
    Collections_EmptyListIterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    bool hasNext();
    ::java::lang::Object* next();
    void remove();

public: /* package */
    static Collections_EmptyListIterator*& EMPTY_ITERATOR();

private:
    virtual ::java::lang::Class* getClass0();
};
