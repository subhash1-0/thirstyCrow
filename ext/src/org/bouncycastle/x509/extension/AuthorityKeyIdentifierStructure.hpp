// Generated from /pastry-2.1/lib/bouncycastle.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/x509/extension/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/asn1/x509/AuthorityKeyIdentifier.hpp>

struct default_init_tag;

class org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure
    : public ::org::bouncycastle::asn1::x509::AuthorityKeyIdentifier
{

public:
    typedef ::org::bouncycastle::asn1::x509::AuthorityKeyIdentifier super;

protected:
    void ctor(::int8_tArray* arg0);
    void ctor(::java::security::cert::X509Certificate* arg0);
    void ctor(::java::security::PublicKey* arg0);
    /*static ::org::bouncycastle::asn1::ASN1Sequence* fromCertificate(::java::security::cert::X509Certificate* arg0); (private) */
    /*static ::org::bouncycastle::asn1::ASN1Sequence* fromKey(::java::security::PublicKey* arg0); (private) */

    // Generated

public:
    AuthorityKeyIdentifierStructure(::int8_tArray* arg0);
    AuthorityKeyIdentifierStructure(::java::security::cert::X509Certificate* arg0);
    AuthorityKeyIdentifierStructure(::java::security::PublicKey* arg0);
protected:
    AuthorityKeyIdentifierStructure(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
