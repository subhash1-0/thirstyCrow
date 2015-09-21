// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/security/auth/x500/fwd-pastry-2.1.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/X509Extension.hpp>

struct default_init_tag;

class java::security::cert::X509Certificate
    : public Certificate
    , public virtual X509Extension
{

public:
    typedef Certificate super;

private:
    ::javax::security::auth::x500::X500Principal* issuerX500Principal {  };
    static constexpr int64_t serialVersionUID { int64_t(-2491127588187038216LL) };
    ::javax::security::auth::x500::X500Principal* subjectX500Principal {  };

protected:
    void ctor();

public:
    virtual void checkValidity() = 0;
    virtual void checkValidity(::java::util::Date* arg0) = 0;
    virtual int32_t getBasicConstraints() = 0;
    virtual ::java::util::List* getExtendedKeyUsage();
    virtual ::java::util::Collection* getIssuerAlternativeNames();
    virtual ::java::security::Principal* getIssuerDN() = 0;
    virtual ::boolArray* getIssuerUniqueID() = 0;
    virtual ::javax::security::auth::x500::X500Principal* getIssuerX500Principal();
    virtual ::boolArray* getKeyUsage() = 0;
    virtual ::java::util::Date* getNotAfter() = 0;
    virtual ::java::util::Date* getNotBefore() = 0;
    virtual ::java::math::BigInteger* getSerialNumber() = 0;
    virtual ::java::lang::String* getSigAlgName() = 0;
    virtual ::java::lang::String* getSigAlgOID() = 0;
    virtual ::int8_tArray* getSigAlgParams() = 0;
    virtual ::int8_tArray* getSignature() = 0;
    virtual ::java::util::Collection* getSubjectAlternativeNames();
    virtual ::java::security::Principal* getSubjectDN() = 0;
    virtual ::boolArray* getSubjectUniqueID() = 0;
    virtual ::javax::security::auth::x500::X500Principal* getSubjectX500Principal();
    virtual ::int8_tArray* getTBSCertificate() = 0;
    virtual int32_t getVersion() = 0;
    void verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1) override;

    // Generated

public: /* protected */
    X509Certificate();
protected:
    X509Certificate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void verify(::java::security::PublicKey* arg0) = 0;
    virtual void verify(::java::security::PublicKey* arg0, ::java::lang::String* arg1) = 0;

private:
    virtual ::java::lang::Class* getClass0();
};
