// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/security/GeneralSecurityException.hpp>

struct default_init_tag;

class java::security::cert::CertificateException
    : public ::java::security::GeneralSecurityException
{

public:
    typedef ::java::security::GeneralSecurityException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3192535253797119798LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    CertificateException();
    CertificateException(::java::lang::String* arg0);
    CertificateException(::java::lang::Throwable* arg0);
    CertificateException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    CertificateException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
