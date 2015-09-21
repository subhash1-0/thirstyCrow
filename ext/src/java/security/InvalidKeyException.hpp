// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/KeyException.hpp>

struct default_init_tag;

class java::security::InvalidKeyException
    : public KeyException
{

public:
    typedef KeyException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(5698479920593359816LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    InvalidKeyException();
    InvalidKeyException(::java::lang::String* arg0);
    InvalidKeyException(::java::lang::Throwable* arg0);
    InvalidKeyException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    InvalidKeyException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
