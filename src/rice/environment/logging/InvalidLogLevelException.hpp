// Generated from /pastry-2.1/src/rice/environment/logging/InvalidLogLevelException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class rice::environment::logging::InvalidLogLevelException
    : public ::java::lang::RuntimeException
{

public:
    typedef ::java::lang::RuntimeException super;
protected:
    void ctor(::java::lang::String* key, ::java::lang::String* val);

    // Generated

public:
    InvalidLogLevelException(::java::lang::String* key, ::java::lang::String* val);
protected:
    InvalidLogLevelException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
