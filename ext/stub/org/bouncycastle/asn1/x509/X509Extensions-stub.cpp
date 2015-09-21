// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/asn1/x509/X509Extensions.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::asn1::x509::X509Extensions::X509Extensions(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::asn1::x509::X509Extensions::X509Extensions(::org::bouncycastle::asn1::ASN1Sequence* arg0)
    : X509Extensions(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::asn1::x509::X509Extensions::X509Extensions(::java::util::Hashtable* arg0)
    : X509Extensions(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::asn1::x509::X509Extensions::X509Extensions(::java::util::Vector* arg0, ::java::util::Hashtable* arg1)
    : X509Extensions(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

org::bouncycastle::asn1::x509::X509Extensions::X509Extensions(::java::util::Vector* arg0, ::java::util::Vector* arg1)
    : X509Extensions(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::AuditIdentity()
{
    clinit();
    return AuditIdentity_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::AuditIdentity_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::AuthorityInfoAccess()
{
    clinit();
    return AuthorityInfoAccess_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::AuthorityInfoAccess_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::AuthorityKeyIdentifier()
{
    clinit();
    return AuthorityKeyIdentifier_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::AuthorityKeyIdentifier_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::BasicConstraints()
{
    clinit();
    return BasicConstraints_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::BasicConstraints_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::BiometricInfo()
{
    clinit();
    return BiometricInfo_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::BiometricInfo_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::CRLDistributionPoints()
{
    clinit();
    return CRLDistributionPoints_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::CRLDistributionPoints_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::CRLNumber()
{
    clinit();
    return CRLNumber_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::CRLNumber_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::CertificateIssuer()
{
    clinit();
    return CertificateIssuer_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::CertificateIssuer_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::CertificatePolicies()
{
    clinit();
    return CertificatePolicies_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::CertificatePolicies_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::DeltaCRLIndicator()
{
    clinit();
    return DeltaCRLIndicator_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::DeltaCRLIndicator_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::ExtendedKeyUsage()
{
    clinit();
    return ExtendedKeyUsage_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::ExtendedKeyUsage_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::FreshestCRL()
{
    clinit();
    return FreshestCRL_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::FreshestCRL_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::InhibitAnyPolicy()
{
    clinit();
    return InhibitAnyPolicy_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::InhibitAnyPolicy_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::InstructionCode()
{
    clinit();
    return InstructionCode_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::InstructionCode_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::InvalidityDate()
{
    clinit();
    return InvalidityDate_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::InvalidityDate_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::IssuerAlternativeName()
{
    clinit();
    return IssuerAlternativeName_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::IssuerAlternativeName_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::IssuingDistributionPoint()
{
    clinit();
    return IssuingDistributionPoint_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::IssuingDistributionPoint_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::KeyUsage()
{
    clinit();
    return KeyUsage_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::KeyUsage_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::LogoType()
{
    clinit();
    return LogoType_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::LogoType_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::NameConstraints()
{
    clinit();
    return NameConstraints_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::NameConstraints_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::NoRevAvail()
{
    clinit();
    return NoRevAvail_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::NoRevAvail_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::PolicyConstraints()
{
    clinit();
    return PolicyConstraints_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::PolicyConstraints_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::PolicyMappings()
{
    clinit();
    return PolicyMappings_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::PolicyMappings_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::PrivateKeyUsagePeriod()
{
    clinit();
    return PrivateKeyUsagePeriod_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::PrivateKeyUsagePeriod_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::QCStatements()
{
    clinit();
    return QCStatements_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::QCStatements_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::ReasonCode()
{
    clinit();
    return ReasonCode_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::ReasonCode_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::SubjectAlternativeName()
{
    clinit();
    return SubjectAlternativeName_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::SubjectAlternativeName_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::SubjectDirectoryAttributes()
{
    clinit();
    return SubjectDirectoryAttributes_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::SubjectDirectoryAttributes_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::SubjectInfoAccess()
{
    clinit();
    return SubjectInfoAccess_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::SubjectInfoAccess_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::SubjectKeyIdentifier()
{
    clinit();
    return SubjectKeyIdentifier_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::SubjectKeyIdentifier_;
org::bouncycastle::asn1::DERObjectIdentifier*& org::bouncycastle::asn1::x509::X509Extensions::TargetInformation()
{
    clinit();
    return TargetInformation_;
}
org::bouncycastle::asn1::DERObjectIdentifier* org::bouncycastle::asn1::x509::X509Extensions::TargetInformation_;

void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::org::bouncycastle::asn1::ASN1Sequence* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::org::bouncycastle::asn1::ASN1Sequence* arg0)");
}

void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Hashtable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Hashtable* arg0)");
}

void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Vector* arg0, ::java::util::Hashtable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Vector* arg0, ::java::util::Hashtable* arg1)");
}

void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Vector* arg0, ::java::util::Vector* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::X509Extensions::ctor(::java::util::Vector* arg0, ::java::util::Vector* arg1)");
}

bool org::bouncycastle::asn1::x509::X509Extensions::equivalent(X509Extensions* arg0)
{ /* stub */
    unimplemented_(u"bool org::bouncycastle::asn1::x509::X509Extensions::equivalent(X509Extensions* arg0)");
    return 0;
}

org::bouncycastle::asn1::x509::X509Extension* org::bouncycastle::asn1::x509::X509Extensions::getExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0)
{ /* stub */
    unimplemented_(u"org::bouncycastle::asn1::x509::X509Extension* org::bouncycastle::asn1::x509::X509Extensions::getExtension(::org::bouncycastle::asn1::DERObjectIdentifier* arg0)");
    return 0;
}

org::bouncycastle::asn1::x509::X509Extensions* org::bouncycastle::asn1::x509::X509Extensions::getInstance(::java::lang::Object* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"org::bouncycastle::asn1::x509::X509Extensions* org::bouncycastle::asn1::x509::X509Extensions::getInstance(::java::lang::Object* arg0)");
    return 0;
}

org::bouncycastle::asn1::x509::X509Extensions* org::bouncycastle::asn1::x509::X509Extensions::getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"org::bouncycastle::asn1::x509::X509Extensions* org::bouncycastle::asn1::x509::X509Extensions::getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1)");
    return 0;
}

java::util::Enumeration* org::bouncycastle::asn1::x509::X509Extensions::oids()
{ /* stub */
    unimplemented_(u"java::util::Enumeration* org::bouncycastle::asn1::x509::X509Extensions::oids()");
    return 0;
}

org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::x509::X509Extensions::toASN1Object()
{ /* stub */
    unimplemented_(u"org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::x509::X509Extensions::toASN1Object()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::asn1::x509::X509Extensions::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.asn1.x509.X509Extensions", 41);
    return c;
}

java::lang::Class* org::bouncycastle::asn1::x509::X509Extensions::getClass0()
{
    return class_();
}

