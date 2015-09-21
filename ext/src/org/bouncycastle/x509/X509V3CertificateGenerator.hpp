// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/security/auth/x500/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/x509/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::bouncycastle::x509::X509V3CertificateGenerator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::org::bouncycastle::asn1::x509::X509ExtensionsGenerator* extGenerator {  };
    ::org::bouncycastle::asn1::x509::AlgorithmIdentifier* sigAlgId {  };
    ::org::bouncycastle::asn1::DERObjectIdentifier* sigOID {  };
    ::java::lang::String* signatureAlgorithm {  };
    ::org::bouncycastle::asn1::x509::V3TBSCertificateGenerator* tbsGen {  };

protected:
    void ctor();

public:
    virtual void addExtension(::java::lang::String* arg0, bool arg1, ::org::bouncycastle::asn1::DEREncodable* arg2);
    virtual void addExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0, bool arg1, ::org::bouncycastle::asn1::DEREncodable* arg2);
    virtual void addExtension(::java::lang::String* arg0, bool arg1, ::int8_tArray* arg2);
    virtual void addExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0, bool arg1, ::int8_tArray* arg2);
    virtual void copyAndAddExtension(::java::lang::String* arg0, bool arg1, ::java::security::cert::X509Certificate* arg2);
    virtual void copyAndAddExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0, bool arg1, ::java::security::cert::X509Certificate* arg2);
    virtual ::java::security::cert::X509Certificate* generate(::java::security::PrivateKey* arg0);
    virtual ::java::security::cert::X509Certificate* generate(::java::security::PrivateKey* arg0, ::java::security::SecureRandom* arg1);
    virtual ::java::security::cert::X509Certificate* generate(::java::security::PrivateKey* arg0, ::java::lang::String* arg1);
    virtual ::java::security::cert::X509Certificate* generate(::java::security::PrivateKey* arg0, ::java::lang::String* arg1, ::java::security::SecureRandom* arg2);
    /*::java::security::cert::X509Certificate* generateJcaObject(::org::bouncycastle::asn1::x509::TBSCertificateStructure* arg0, ::int8_tArray* arg1); (private) */
    /*::org::bouncycastle::asn1::x509::TBSCertificateStructure* generateTbsCert(); (private) */
    virtual ::java::security::cert::X509Certificate* generateX509Certificate(::java::security::PrivateKey* arg0);
    virtual ::java::security::cert::X509Certificate* generateX509Certificate(::java::security::PrivateKey* arg0, ::java::security::SecureRandom* arg1);
    virtual ::java::security::cert::X509Certificate* generateX509Certificate(::java::security::PrivateKey* arg0, ::java::lang::String* arg1);
    virtual ::java::security::cert::X509Certificate* generateX509Certificate(::java::security::PrivateKey* arg0, ::java::lang::String* arg1, ::java::security::SecureRandom* arg2);
    virtual ::java::util::Iterator* getSignatureAlgNames();
    virtual void reset();
    virtual void setIssuerDN(::javax::security::auth::x500::X500Principal* arg0);
    virtual void setIssuerDN(::org::bouncycastle::asn1::x509::X509Name* arg0);
    virtual void setNotAfter(::java::util::Date* arg0);
    virtual void setNotBefore(::java::util::Date* arg0);
    virtual void setPublicKey(::java::security::PublicKey* arg0);
    virtual void setSerialNumber(::java::math::BigInteger* arg0);
    virtual void setSignatureAlgorithm(::java::lang::String* arg0);
    virtual void setSubjectDN(::javax::security::auth::x500::X500Principal* arg0);
    virtual void setSubjectDN(::org::bouncycastle::asn1::x509::X509Name* arg0);

    // Generated
    X509V3CertificateGenerator();
protected:
    X509V3CertificateGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
