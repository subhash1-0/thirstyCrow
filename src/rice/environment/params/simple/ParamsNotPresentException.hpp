// Generated from /pastry-2.1/src/rice/environment/params/simple/ParamsNotPresentException.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/params/simple/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class rice::environment::params::simple::ParamsNotPresentException
    : public ::java::lang::RuntimeException
{

public:
    typedef ::java::lang::RuntimeException super;

public: /* package */
    ::java::lang::Exception* subexception {  };
protected:
    void ctor(::java::lang::String* reason, ::java::lang::Exception* e);

public:
    void printStackTrace(::java::io::PrintStream* arg0) override;
    void printStackTrace() override;
    void printStackTrace(::java::io::PrintWriter* pw) override;

    // Generated
    ParamsNotPresentException(::java::lang::String* reason, ::java::lang::Exception* e);
protected:
    ParamsNotPresentException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
