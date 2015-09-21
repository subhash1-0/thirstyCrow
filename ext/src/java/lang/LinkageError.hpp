// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Error.hpp>

struct default_init_tag;

class java::lang::LinkageError
    : public Error
{

public:
    typedef Error super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3579600108157160122LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(String* arg0, Throwable* arg1);

    // Generated

public:
    LinkageError();
    LinkageError(String* arg0);
    LinkageError(String* arg0, Throwable* arg1);
protected:
    LinkageError(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
