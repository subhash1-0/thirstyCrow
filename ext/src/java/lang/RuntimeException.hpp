// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class java::lang::RuntimeException
    : public Exception
{

public:
    typedef Exception super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-7034897190745766939LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);
    void ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3);

    // Generated

public:
    RuntimeException();
    RuntimeException(String* arg0);
    RuntimeException(Throwable* arg0);
    RuntimeException(String* arg0, Throwable* arg1);

public: /* protected */
    RuntimeException(String* arg0, Throwable* arg1, bool arg2, bool arg3);
protected:
    RuntimeException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
