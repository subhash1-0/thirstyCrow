// Generated from /pastry-2.1/src/rice/p2p/commonapi/RangeCannotBeDeterminedException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/RuntimeException.hpp>

struct default_init_tag;

class rice::p2p::commonapi::RangeCannotBeDeterminedException
    : public ::java::lang::RuntimeException
{

public:
    typedef ::java::lang::RuntimeException super;
protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    RangeCannotBeDeterminedException();
    RangeCannotBeDeterminedException(::java::lang::String* arg0);
    RangeCannotBeDeterminedException(::java::lang::Throwable* arg0);
    RangeCannotBeDeterminedException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    RangeCannotBeDeterminedException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
