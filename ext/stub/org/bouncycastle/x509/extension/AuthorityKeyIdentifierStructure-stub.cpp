// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/x509/extension/AuthorityKeyIdentifierStructure.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::AuthorityKeyIdentifierStructure(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::AuthorityKeyIdentifierStructure(::int8_tArray* arg0)
    : AuthorityKeyIdentifierStructure(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::AuthorityKeyIdentifierStructure(::java::security::cert::X509Certificate* arg0)
    : AuthorityKeyIdentifierStructure(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::AuthorityKeyIdentifierStructure(::java::security::PublicKey* arg0)
    : AuthorityKeyIdentifierStructure(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::int8_tArray* arg0)");
}

void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::java::security::cert::X509Certificate* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::java::security::cert::X509Certificate* arg0)");
}

void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::java::security::PublicKey* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::ctor(::java::security::PublicKey* arg0)");
}

/* private: org::bouncycastle::asn1::ASN1Sequence* org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::fromCertificate(::java::security::cert::X509Certificate* arg0) */
/* private: org::bouncycastle::asn1::ASN1Sequence* org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::fromKey(::java::security::PublicKey* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.x509.extension.AuthorityKeyIdentifierStructure", 63);
    return c;
}

java::lang::Class* org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure::getClass0()
{
    return class_();
}

