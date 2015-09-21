// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/x509/extension/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/SubjectKeyIdentifier.hpp>

struct default_init_tag;

class org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure
    : public ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier
{

public:
    typedef ::org::bouncycastle::asn1::x509::SubjectKeyIdentifier super;

private:
    ::org::bouncycastle::asn1::x509::AuthorityKeyIdentifier* authKeyID {  };

protected:
    void ctor(::int8_tArray* arg0);
    void ctor(::java::security::PublicKey* arg0);
    /*static ::org::bouncycastle::asn1::ASN1OctetString* fromPublicKey(::java::security::PublicKey* arg0); (private) */

    // Generated

public:
    SubjectKeyIdentifierStructure(::int8_tArray* arg0);
    SubjectKeyIdentifierStructure(::java::security::PublicKey* arg0);
protected:
    SubjectKeyIdentifierStructure(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
