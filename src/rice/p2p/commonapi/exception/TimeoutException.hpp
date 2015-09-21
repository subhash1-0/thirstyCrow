// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/TimeoutException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/AppSocketException.hpp>

struct default_init_tag;

class rice::p2p::commonapi::exception::TimeoutException
    : public AppSocketException
{

public:
    typedef AppSocketException super;
protected:
    void ctor();
    void ctor(::java::lang::String* string);
    void ctor(::java::lang::Throwable* reason);

    // Generated

public:
    TimeoutException();
    TimeoutException(::java::lang::String* string);
    TimeoutException(::java::lang::Throwable* reason);
protected:
    TimeoutException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
