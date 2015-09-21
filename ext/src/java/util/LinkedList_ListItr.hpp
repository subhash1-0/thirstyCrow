// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ListIterator.hpp>

struct default_init_tag;

class java::util::LinkedList_ListItr
    : public virtual ::java::lang::Object
    , public virtual ListIterator
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t expectedModCount {  };
    LinkedList_Node* lastReturned {  };
    LinkedList_Node* next_ {  };
    int32_t nextIndex_ {  };

public: /* package */
    LinkedList* this$0 {  };

protected:
    void ctor(int32_t arg0);

public:
    void add(::java::lang::Object* arg0) override;

public: /* package */
    void checkForComodification();

public:
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    bool hasNext() override;
    bool hasPrevious() override;
    ::java::lang::Object* next() override;
    int32_t nextIndex() override;
    ::java::lang::Object* previous() override;
    int32_t previousIndex() override;
    void remove() override;
    void set(::java::lang::Object* arg0) override;

    // Generated

public: /* package */
    LinkedList_ListItr(LinkedList *LinkedList_this, int32_t arg0);
protected:
    LinkedList_ListItr(LinkedList *LinkedList_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    LinkedList *LinkedList_this;

private:
    virtual ::java::lang::Class* getClass0();
};
