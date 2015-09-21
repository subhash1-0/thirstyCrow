// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/Vector.hpp>

struct default_init_tag;

class java::util::Stack
    : public Vector
{

public:
    typedef Vector super;

private:
    static constexpr int64_t serialVersionUID { int64_t(1224463164541339165LL) };

protected:
    void ctor();

public:
    virtual bool empty();
    virtual ::java::lang::Object* peek();
    virtual ::java::lang::Object* pop();
    virtual ::java::lang::Object* push(::java::lang::Object* arg0);
    virtual int32_t search(::java::lang::Object* arg0);

    // Generated
    Stack();
protected:
    Stack(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
