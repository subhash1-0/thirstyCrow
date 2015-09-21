// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/asn1/x509/SubjectKeyIdentifier.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::asn1::x509::SubjectKeyIdentifier::SubjectKeyIdentifier(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::asn1::x509::SubjectKeyIdentifier::SubjectKeyIdentifier(::int8_tArray* arg0)
    : SubjectKeyIdentifier(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::asn1::x509::SubjectKeyIdentifier::SubjectKeyIdentifier(::org::bouncycastle::asn1::ASN1OctetString* arg0)
    : SubjectKeyIdentifier(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

org::bouncycastle::asn1::x509::SubjectKeyIdentifier::SubjectKeyIdentifier(SubjectPublicKeyInfo* arg0)
    : SubjectKeyIdentifier(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(::int8_tArray* arg0)");
}

void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(::org::bouncycastle::asn1::ASN1OctetString* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(::org::bouncycastle::asn1::ASN1OctetString* arg0)");
}

void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(SubjectPublicKeyInfo* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier::ctor(SubjectPublicKeyInfo* arg0)");
}

org::bouncycastle::asn1::x509::SubjectKeyIdentifier* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getInstance(::java::lang::Object* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"org::bouncycastle::asn1::x509::SubjectKeyIdentifier* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getInstance(::java::lang::Object* arg0)");
    return 0;
}

org::bouncycastle::asn1::x509::SubjectKeyIdentifier* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"org::bouncycastle::asn1::x509::SubjectKeyIdentifier* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1)");
    return 0;
}

int8_tArray* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getKeyIdentifier()
{ /* stub */
    unimplemented_(u"int8_tArray* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getKeyIdentifier()");
    return 0;
}

org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::toASN1Object()
{ /* stub */
    unimplemented_(u"org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::toASN1Object()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.asn1.x509.SubjectKeyIdentifier", 47);
    return c;
}

java::lang::Class* org::bouncycastle::asn1::x509::SubjectKeyIdentifier::getClass0()
{
    return class_();
}

