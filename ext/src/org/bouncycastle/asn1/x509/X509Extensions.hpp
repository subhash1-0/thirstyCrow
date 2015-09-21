// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/ASN1Encodable.hpp>

struct default_init_tag;

class org::bouncycastle::asn1::x509::X509Extensions
    : public ::org::bouncycastle::asn1::ASN1Encodable
{

public:
    typedef ::org::bouncycastle::asn1::ASN1Encodable super;

private:
    static ::org::bouncycastle::asn1::DERObjectIdentifier* AuditIdentity_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* AuthorityInfoAccess_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* AuthorityKeyIdentifier_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* BasicConstraints_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* BiometricInfo_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* CRLDistributionPoints_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* CRLNumber_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* CertificateIssuer_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* CertificatePolicies_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* DeltaCRLIndicator_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* ExtendedKeyUsage_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* FreshestCRL_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* InhibitAnyPolicy_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* InstructionCode_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* InvalidityDate_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* IssuerAlternativeName_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* IssuingDistributionPoint_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* KeyUsage_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* LogoType_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* NameConstraints_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* NoRevAvail_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* PolicyConstraints_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* PolicyMappings_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* PrivateKeyUsagePeriod_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* QCStatements_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* ReasonCode_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* SubjectAlternativeName_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* SubjectDirectoryAttributes_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* SubjectInfoAccess_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* SubjectKeyIdentifier_;
    static ::org::bouncycastle::asn1::DERObjectIdentifier* TargetInformation_;
    ::java::util::Hashtable* extensions {  };
    ::java::util::Vector* ordering {  };

protected:
    void ctor(::org::bouncycastle::asn1::ASN1Sequence* arg0);
    void ctor(::java::util::Hashtable* arg0);
    void ctor(::java::util::Vector* arg0, ::java::util::Hashtable* arg1);
    void ctor(::java::util::Vector* arg0, ::java::util::Vector* arg1);

public:
    virtual bool equivalent(X509Extensions* arg0);
    virtual X509Extension* getExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0);
    static X509Extensions* getInstance(::java::lang::Object* arg0);
    static X509Extensions* getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1);
    virtual ::java::util::Enumeration* oids();
    ::org::bouncycastle::asn1::DERObject* toASN1Object() override;

    // Generated
    X509Extensions(::org::bouncycastle::asn1::ASN1Sequence* arg0);
    X509Extensions(::java::util::Hashtable* arg0);
    X509Extensions(::java::util::Vector* arg0, ::java::util::Hashtable* arg1);
    X509Extensions(::java::util::Vector* arg0, ::java::util::Vector* arg1);
protected:
    X509Extensions(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& AuditIdentity();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& AuthorityInfoAccess();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& AuthorityKeyIdentifier();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& BasicConstraints();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& BiometricInfo();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& CRLDistributionPoints();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& CRLNumber();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& CertificateIssuer();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& CertificatePolicies();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& DeltaCRLIndicator();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& ExtendedKeyUsage();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& FreshestCRL();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& InhibitAnyPolicy();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& InstructionCode();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& InvalidityDate();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& IssuerAlternativeName();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& IssuingDistributionPoint();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& KeyUsage();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& LogoType();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& NameConstraints();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& NoRevAvail();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& PolicyConstraints();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& PolicyMappings();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& PrivateKeyUsagePeriod();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& QCStatements();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& ReasonCode();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& SubjectAlternativeName();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& SubjectDirectoryAttributes();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& SubjectInfoAccess();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& SubjectKeyIdentifier();
    static ::org::bouncycastle::asn1::DERObjectIdentifier*& TargetInformation();

private:
    virtual ::java::lang::Class* getClass0();
};
