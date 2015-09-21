// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class java::lang::UnsupportedOperationException
    : public RuntimeException
{

public:
    typedef RuntimeException super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-1242599979055084673LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);

    // Generated

public:
    UnsupportedOperationException();
    UnsupportedOperationException(String* arg0);
    UnsupportedOperationException(Throwable* arg0);
    UnsupportedOperationException(String* arg0, Throwable* arg1);
protected:
    UnsupportedOperationException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
