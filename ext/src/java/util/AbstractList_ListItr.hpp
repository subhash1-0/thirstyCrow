// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList_Itr.hpp>
#include <java/util/ListIterator.hpp>

struct default_init_tag;

class java::util::AbstractList_ListItr
    : public AbstractList_Itr
    , public virtual ListIterator
{

public:
    typedef AbstractList_Itr super;

public: /* package */
    AbstractList* this$0 {  };

protected:
    void ctor(int32_t arg0);

public:
    void add(::java::lang::Object* arg0) override;
    bool hasPrevious() override;
    int32_t nextIndex() override;
    ::java::lang::Object* previous() override;
    int32_t previousIndex() override;
    void set(::java::lang::Object* arg0) override;

    // Generated

public: /* package */
    AbstractList_ListItr(AbstractList *AbstractList_this, int32_t arg0);
protected:
    AbstractList_ListItr(AbstractList *AbstractList_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool hasNext();
    ::java::lang::Object* next();
    void remove();

private:
    virtual ::java::lang::Class* getClass0();
};
