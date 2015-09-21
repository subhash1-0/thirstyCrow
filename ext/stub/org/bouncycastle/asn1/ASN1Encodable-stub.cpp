// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/asn1/ASN1Encodable.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::asn1::ASN1Encodable::ASN1Encodable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::asn1::ASN1Encodable::ASN1Encodable()
    : ASN1Encodable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::String*& org::bouncycastle::asn1::ASN1Encodable::BER()
{
    clinit();
    return BER_;
}
java::lang::String* org::bouncycastle::asn1::ASN1Encodable::BER_;
java::lang::String*& org::bouncycastle::asn1::ASN1Encodable::DER()
{
    clinit();
    return DER_;
}
java::lang::String* org::bouncycastle::asn1::ASN1Encodable::DER_;

void ::org::bouncycastle::asn1::ASN1Encodable::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::asn1::ASN1Encodable::ctor()");
}

bool org::bouncycastle::asn1::ASN1Encodable::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool org::bouncycastle::asn1::ASN1Encodable::equals(::java::lang::Object* arg0)");
    return 0;
}

int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getDEREncoded()
{ /* stub */
    unimplemented_(u"int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getDEREncoded()");
    return 0;
}

org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::ASN1Encodable::getDERObject()
{ /* stub */
    unimplemented_(u"org::bouncycastle::asn1::DERObject* org::bouncycastle::asn1::ASN1Encodable::getDERObject()");
    return 0;
}

int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getEncoded()
{ /* stub */
    unimplemented_(u"int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getEncoded()");
    return 0;
}

int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getEncoded(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* org::bouncycastle::asn1::ASN1Encodable::getEncoded(::java::lang::String* arg0)");
    return 0;
}

int32_t org::bouncycastle::asn1::ASN1Encodable::hashCode()
{ /* stub */
    unimplemented_(u"int32_t org::bouncycastle::asn1::ASN1Encodable::hashCode()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::asn1::ASN1Encodable::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.asn1.ASN1Encodable", 35);
    return c;
}

java::lang::Class* org::bouncycastle::asn1::ASN1Encodable::getClass0()
{
    return class_();
}

