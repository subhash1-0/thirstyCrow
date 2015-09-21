// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/ref/Reference.hpp>

struct default_init_tag;

class java::lang::ref::SoftReference
    : public Reference
{

public:
    typedef Reference super;

private:
    static int64_t clock_;
    int64_t timestamp {  };

protected:
    void ctor(::java::lang::Object* arg0);
    void ctor(::java::lang::Object* arg0, ReferenceQueue* arg1);

public:
    ::java::lang::Object* get() override;

    // Generated
    SoftReference(::java::lang::Object* arg0);
    SoftReference(::java::lang::Object* arg0, ReferenceQueue* arg1);
protected:
    SoftReference(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int64_t& clock();
    virtual ::java::lang::Class* getClass0();
};
