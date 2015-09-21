// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/GeneralSecurityException.hpp>

struct default_init_tag;

class java::security::InvalidAlgorithmParameterException
    : public GeneralSecurityException
{

public:
    typedef GeneralSecurityException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(2864672297499471472LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    InvalidAlgorithmParameterException();
    InvalidAlgorithmParameterException(::java::lang::String* arg0);
    InvalidAlgorithmParameterException(::java::lang::Throwable* arg0);
    InvalidAlgorithmParameterException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    InvalidAlgorithmParameterException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
