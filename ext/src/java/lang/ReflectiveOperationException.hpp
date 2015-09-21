// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class java::lang::ReflectiveOperationException
    : public Exception
{

public:
    typedef Exception super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(123456789LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);

    // Generated

public:
    ReflectiveOperationException();
    ReflectiveOperationException(String* arg0);
    ReflectiveOperationException(Throwable* arg0);
    ReflectiveOperationException(String* arg0, Throwable* arg1);
protected:
    ReflectiveOperationException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
