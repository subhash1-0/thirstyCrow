// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ReflectiveOperationException.hpp>

struct default_init_tag;

class java::lang::ClassNotFoundException
    : public ReflectiveOperationException
{

public:
    typedef ReflectiveOperationException super;

private:
    Throwable* ex {  };
    static constexpr int64_t serialVersionUID { int64_t(9176873029745254542LL) };

protected:
    void ctor();
    void ctor(String* arg0);
    void ctor(String* arg0, Throwable* arg1);

public:
    Throwable* getCause() override;
    virtual Throwable* getException();

    // Generated
    ClassNotFoundException();
    ClassNotFoundException(String* arg0);
    ClassNotFoundException(String* arg0, Throwable* arg1);
protected:
    ClassNotFoundException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
