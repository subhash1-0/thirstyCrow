// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/ASN1Encodable.hpp>

struct default_init_tag;

class org::bouncycastle::asn1::x509::SubjectKeyIdentifier
    : public ::org::bouncycastle::asn1::ASN1Encodable
{

public:
    typedef ::org::bouncycastle::asn1::ASN1Encodable super;

private:
    ::int8_tArray* keyidentifier {  };

protected:
    void ctor(::int8_tArray* arg0);
    void ctor(::org::bouncycastle::asn1::ASN1OctetString* arg0);
    void ctor(SubjectPublicKeyInfo* arg0);

public:
    static SubjectKeyIdentifier* getInstance(::java::lang::Object* arg0);
    static SubjectKeyIdentifier* getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1);
    virtual ::int8_tArray* getKeyIdentifier();
    ::org::bouncycastle::asn1::DERObject* toASN1Object() override;

    // Generated
    SubjectKeyIdentifier(::int8_tArray* arg0);
    SubjectKeyIdentifier(::org::bouncycastle::asn1::ASN1OctetString* arg0);
    SubjectKeyIdentifier(SubjectPublicKeyInfo* arg0);
protected:
    SubjectKeyIdentifier(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
