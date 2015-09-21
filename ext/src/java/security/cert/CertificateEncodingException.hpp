// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/security/cert/CertificateException.hpp>

struct default_init_tag;

class java::security::cert::CertificateEncodingException
    : public CertificateException
{

public:
    typedef CertificateException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(6219492851589449162LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    void ctor(::java::lang::Throwable* arg0);
    void ctor(::java::lang::String* arg0, ::java::lang::Throwable* arg1);

    // Generated

public:
    CertificateEncodingException();
    CertificateEncodingException(::java::lang::String* arg0);
    CertificateEncodingException(::java::lang::Throwable* arg0);
    CertificateEncodingException(::java::lang::String* arg0, ::java::lang::Throwable* arg1);
protected:
    CertificateEncodingException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
