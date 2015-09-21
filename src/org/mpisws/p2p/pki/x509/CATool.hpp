// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/CATool.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::pki::x509::CATool
    : public virtual ::java::lang::Object
{
    virtual ::java::security::cert::X509Certificate* sign(::java::lang::String* CN, ::java::security::PublicKey* key) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */ = 0;
    virtual ::java::security::cert::X509Certificate* sign(::java::lang::String* CN, ::java::security::PublicKey* publicKey, ::java::util::Date* expiryDate, int64_t serialNumber) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */ = 0;
    virtual ::java::security::cert::X509Certificate* getCertificate() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
