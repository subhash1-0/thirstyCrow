// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>

struct default_init_tag;

class java::util::AbstractSequentialList
    : public AbstractList
{

public:
    typedef AbstractList super;

protected:
    void ctor();

public:
    void add(int32_t arg0, ::java::lang::Object* arg1) override;
    bool addAll(int32_t arg0, Collection* arg1) override;
    ::java::lang::Object* get(int32_t arg0) override;
    Iterator* iterator() override;
    ListIterator* listIterator(int32_t arg0) = 0;
    ::java::lang::Object* remove(int32_t arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;

    // Generated

public: /* protected */
    AbstractSequentialList();
protected:
    AbstractSequentialList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool add(::java::lang::Object* arg0);
    ListIterator* listIterator();
    bool addAll(Collection* c);
    bool remove(::java::lang::Object* o);

private:
    virtual ::java::lang::Class* getClass0();
};
