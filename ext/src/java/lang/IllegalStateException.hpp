// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class java::lang::IllegalStateException
    : public RuntimeException
{

public:
    typedef RuntimeException super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-1848914673093119416LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(Throwable* arg0);
    void ctor(String* arg0, Throwable* arg1);

    // Generated

public:
    IllegalStateException();
    IllegalStateException(String* arg0);
    IllegalStateException(Throwable* arg0);
    IllegalStateException(String* arg0, Throwable* arg1);
protected:
    IllegalStateException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
