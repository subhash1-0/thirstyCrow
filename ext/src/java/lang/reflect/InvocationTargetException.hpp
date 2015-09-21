// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/ReflectiveOperationException.hpp>

struct default_init_tag;

class java::lang::reflect::InvocationTargetException
    : public ::java::lang::ReflectiveOperationException
{

public:
    typedef ::java::lang::ReflectiveOperationException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(4085088731926701167LL) };
    ::java::lang::Throwable* target {  };

protected:
    void ctor();
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::Throwable* arg0, ::java::lang::String* arg1);

public:
    ::java::lang::Throwable* getCause() override;
    virtual ::java::lang::Throwable* getTargetException();

    // Generated

public: /* protected */
    InvocationTargetException();

public:
    InvocationTargetException(::java::lang::Throwable* arg0);
    InvocationTargetException(::java::lang::Throwable* arg0, ::java::lang::String* arg1);
protected:
    InvocationTargetException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
