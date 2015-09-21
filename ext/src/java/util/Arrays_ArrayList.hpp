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

class java::util::Arrays_ArrayList
    : public AbstractList
    , public virtual RandomAccess
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractList super;

private:
    ::java::lang::ObjectArray* a {  };
    static constexpr int64_t serialVersionUID { int64_t(-2764017481108945198LL) };

protected:
    void ctor(::java::lang::ObjectArray* arg0);

public:
    bool contains(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    int32_t indexOf(::java::lang::Object* arg0) override;
    void replaceAll(::java::util::function::UnaryOperator* arg0) override;
    ::java::lang::Object* set(int32_t arg0, ::java::lang::Object* arg1) override;
    int32_t size() override;
    void sort(Comparator* arg0) override;
    Spliterator* spliterator() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

    // Generated

public: /* package */
    Arrays_ArrayList(::java::lang::ObjectArray* arg0);
protected:
    Arrays_ArrayList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
