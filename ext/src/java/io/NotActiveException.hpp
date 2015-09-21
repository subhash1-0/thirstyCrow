// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/ObjectStreamException.hpp>

struct default_init_tag;

class java::io::NotActiveException
    : public ObjectStreamException
{

public:
    typedef ObjectStreamException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-3893467273049808895LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    NotActiveException();
    NotActiveException(::java::lang::String* arg0);
protected:
    NotActiveException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
