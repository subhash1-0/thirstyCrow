// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/ObjectStreamException.hpp>

struct default_init_tag;

class java::io::InvalidObjectException
    : public ObjectStreamException
{

public:
    typedef ObjectStreamException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3233174318281839583LL) };

protected:
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    InvalidObjectException(::java::lang::String* arg0);
protected:
    InvalidObjectException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
