// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::Dictionary
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual Enumeration* elements() = 0;
    virtual ::java::lang::Object* get(::java::lang::Object* arg0) = 0;
    virtual bool isEmpty() = 0;
    virtual Enumeration* keys() = 0;
    virtual ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) = 0;
    virtual ::java::lang::Object* remove(::java::lang::Object* arg0) = 0;
    virtual int32_t size() = 0;

    // Generated
    Dictionary();
protected:
    Dictionary(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
