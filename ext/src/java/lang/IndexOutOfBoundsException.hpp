// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class java::lang::IndexOutOfBoundsException
    : public RuntimeException
{

public:
    typedef RuntimeException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(234122996006267687LL) };

protected:
    void ctor();
    void ctor(String* arg0);

    // Generated

public:
    IndexOutOfBoundsException();
    IndexOutOfBoundsException(String* arg0);
protected:
    IndexOutOfBoundsException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
