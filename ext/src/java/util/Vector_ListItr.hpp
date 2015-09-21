// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Vector_Itr.hpp>
#include <java/util/ListIterator.hpp>

struct default_init_tag;

class java::util::Vector_ListItr final
    : public Vector_Itr
    , public ListIterator
{

public:
    typedef Vector_Itr super;

public: /* package */
    Vector* this$0 {  };

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
    Vector_ListItr(Vector *Vector_this, int32_t arg0);
protected:
    Vector_ListItr(Vector *Vector_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    bool hasNext();
    ::java::lang::Object* next();
    void remove();

private:
    virtual ::java::lang::Class* getClass0();
};
