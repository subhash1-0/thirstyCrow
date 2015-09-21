// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/x509/extension/SubjectKeyIdentifierStructure.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::SubjectKeyIdentifierStructure(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::SubjectKeyIdentifierStructure(::int8_tArray* arg0)
    : SubjectKeyIdentifierStructure(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::SubjectKeyIdentifierStructure(::java::security::PublicKey* arg0)
    : SubjectKeyIdentifierStructure(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::ctor(::int8_tArray* arg0)");
}

void ::org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::ctor(::java::security::PublicKey* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::ctor(::java::security::PublicKey* arg0)");
}

/* private: org::bouncycastle::asn1::ASN1OctetString* org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::fromPublicKey(::java::security::PublicKey* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.x509.extension.SubjectKeyIdentifierStructure", 61);
    return c;
}

java::lang::Class* org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure::getClass0()
{
    return class_();
}

