// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::ref::Reference
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    Reference* discovered {  };
    static Reference_Lock* lock_;

public: /* package */
    Reference* next {  };

private:
    static Reference* pending_;

public: /* package */
    std::atomic< ReferenceQueue* > queue {  };

private:
    ::java::lang::Object* referent {  };

protected:
    void ctor(::java::lang::Object* arg0);
    void ctor(::java::lang::Object* arg0, ReferenceQueue* arg1);

public:
    virtual void clear();
    virtual bool enqueue();
    virtual ::java::lang::Object* get();
    virtual bool isEnqueued();

    // Generated

public: /* package */
    Reference(::java::lang::Object* arg0);
    Reference(::java::lang::Object* arg0, ReferenceQueue* arg1);
protected:
    Reference(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static Reference_Lock*& lock();
    static Reference*& pending();
    virtual ::java::lang::Class* getClass0();
};
