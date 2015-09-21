// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class java::lang::ref::Reference_ReferenceHandler
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;

protected:
    void ctor(::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);

public:
    void run() override;

    // Generated

public: /* package */
    Reference_ReferenceHandler(::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1);
protected:
    Reference_ReferenceHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
