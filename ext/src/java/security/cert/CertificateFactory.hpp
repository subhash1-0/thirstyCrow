// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::cert::CertificateFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    CertificateFactorySpi* certFacSpi {  };
    ::java::security::Provider* provider {  };
    ::java::lang::String* type {  };

protected:
    void ctor(CertificateFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);

public:
    CRL* generateCRL(::java::io::InputStream* arg0);
    ::java::util::Collection* generateCRLs(::java::io::InputStream* arg0);
    CertPath* generateCertPath(::java::io::InputStream* arg0);
    CertPath* generateCertPath(::java::util::List* arg0);
    CertPath* generateCertPath(::java::io::InputStream* arg0, ::java::lang::String* arg1);
    Certificate* generateCertificate(::java::io::InputStream* arg0);
    ::java::util::Collection* generateCertificates(::java::io::InputStream* arg0);
    ::java::util::Iterator* getCertPathEncodings();
    static CertificateFactory* getInstance(::java::lang::String* arg0);
    static CertificateFactory* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static CertificateFactory* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    ::java::security::Provider* getProvider();
    ::java::lang::String* getType();

    // Generated

public: /* protected */
    CertificateFactory(CertificateFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    CertificateFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
