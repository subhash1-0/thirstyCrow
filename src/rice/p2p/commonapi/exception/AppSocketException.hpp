// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/AppSocketException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/exception/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::p2p::commonapi::exception::AppSocketException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

public: /* package */
    ::java::lang::Throwable* reason_ {  };
protected:
    void ctor();
    void ctor(::java::lang::Throwable* reason);
    void ctor(::java::lang::String* string);

public:
    virtual ::java::lang::Throwable* reason();

    // Generated
    AppSocketException();
    AppSocketException(::java::lang::Throwable* reason);
    AppSocketException(::java::lang::String* string);
protected:
    AppSocketException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
