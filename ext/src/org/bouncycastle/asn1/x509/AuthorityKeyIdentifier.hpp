// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/ASN1Encodable.hpp>

struct default_init_tag;

class org::bouncycastle::asn1::x509::AuthorityKeyIdentifier
    : public ::org::bouncycastle::asn1::ASN1Encodable
{

public:
    typedef ::org::bouncycastle::asn1::ASN1Encodable super;

public: /* package */
    GeneralNames* certissuer {  };
    ::org::bouncycastle::asn1::DERInteger* certserno {  };
    ::org::bouncycastle::asn1::ASN1OctetString* keyidentifier {  };

protected:
    void ctor(::org::bouncycastle::asn1::ASN1Sequence* arg0);
    void ctor(SubjectPublicKeyInfo* arg0);
    void ctor(::int8_tArray* arg0);
    void ctor(GeneralNames* arg0, ::java::math::BigInteger* arg1);
    void ctor(SubjectPublicKeyInfo* arg0, GeneralNames* arg1, ::java::math::BigInteger* arg2);
    void ctor(::int8_tArray* arg0, GeneralNames* arg1, ::java::math::BigInteger* arg2);

public:
    virtual GeneralNames* getAuthorityCertIssuer();
    virtual ::java::math::BigInteger* getAuthorityCertSerialNumber();
    static AuthorityKeyIdentifier* getInstance(::java::lang::Object* arg0);
    static AuthorityKeyIdentifier* getInstance(::org::bouncycastle::asn1::ASN1TaggedObject* arg0, bool arg1);
    virtual ::int8_tArray* getKeyIdentifier();
    ::org::bouncycastle::asn1::DERObject* toASN1Object() override;
    ::java::lang::String* toString() override;

    // Generated
    AuthorityKeyIdentifier(::org::bouncycastle::asn1::ASN1Sequence* arg0);
    AuthorityKeyIdentifier(SubjectPublicKeyInfo* arg0);
    AuthorityKeyIdentifier(::int8_tArray* arg0);
    AuthorityKeyIdentifier(GeneralNames* arg0, ::java::math::BigInteger* arg1);
    AuthorityKeyIdentifier(SubjectPublicKeyInfo* arg0, GeneralNames* arg1, ::java::math::BigInteger* arg2);
    AuthorityKeyIdentifier(::int8_tArray* arg0, GeneralNames* arg1, ::java::math::BigInteger* arg2);
protected:
    AuthorityKeyIdentifier(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
