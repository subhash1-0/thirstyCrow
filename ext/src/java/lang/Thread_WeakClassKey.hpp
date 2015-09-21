// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/ref/WeakReference.hpp>

struct default_init_tag;

class java::lang::Thread_WeakClassKey
    : public ::java::lang::ref::WeakReference
{

public:
    typedef ::java::lang::ref::WeakReference super;

private:
    int32_t hash {  };

protected:
    void ctor(Class* arg0, ::java::lang::ref::ReferenceQueue* arg1);

public:
    bool equals(Object* arg0) override;
    int32_t hashCode() override;

    // Generated

public: /* package */
    Thread_WeakClassKey(Class* arg0, ::java::lang::ref::ReferenceQueue* arg1);
protected:
    Thread_WeakClassKey(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
