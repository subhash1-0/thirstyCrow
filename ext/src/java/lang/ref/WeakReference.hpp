// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/ref/Reference.hpp>

struct default_init_tag;

class java::lang::ref::WeakReference
    : public Reference
{

public:
    typedef Reference super;

protected:
    void ctor(::java::lang::Object* arg0);
    void ctor(::java::lang::Object* arg0, ReferenceQueue* arg1);

    // Generated

public:
    WeakReference(::java::lang::Object* arg0);
    WeakReference(::java::lang::Object* arg0, ReferenceQueue* arg1);
protected:
    WeakReference(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
