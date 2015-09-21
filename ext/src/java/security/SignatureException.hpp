// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/GeneralSecurityException.hpp>

struct default_init_tag;

class java::security::SignatureException
    : public GeneralSecurityException
{

public:
    typedef GeneralSecurityException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(7509989324975124438LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    SignatureException();
    SignatureException(::java::lang::String* arg0);
    SignatureException(::java::lang::Throwable* arg0);
    SignatureException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    SignatureException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
