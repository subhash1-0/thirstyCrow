// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class javax::net::ssl::SSLException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(4511006460650708967LL) };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    SSLException(::java::lang::String* arg0);
    SSLException(::java::lang::Throwable* arg0);
    SSLException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    SSLException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
