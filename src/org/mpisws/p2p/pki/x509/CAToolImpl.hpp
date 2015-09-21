// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/CAToolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/pki/x509/CATool.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class org::mpisws::p2p::pki::x509::CAToolImpl
    : public virtual ::java::lang::Object
    , public virtual CATool
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::security::SecureRandom* random_;
    static ::java::lang::String* DEFAULT_SIGNATURE_ALGORITHM_;

public: /* package */
    ::java::security::cert::X509Certificate* cert {  };
    ::java::security::KeyPair* keyPair {  };
protected:
    void ctor(::java::security::cert::X509Certificate* cert, ::java::security::KeyPair* caPair);

public:
    ::java::security::cert::X509Certificate* getCertificate() override;
    static CAToolImpl* getCATool(::java::lang::String* CN, ::char16_tArray* pw) /* throws(KeyStoreException, NoSuchProviderException, NoSuchAlgorithmException, CertificateException, FileNotFoundException, IOException, UnrecoverableKeyException, InvalidKeyException, IllegalStateException, SignatureException, InvalidAlgorithmParameterException) */;
    static ::rice::p2p::util::tuples::Tuple* generateNewCA(::java::lang::String* CN, ::java::util::Date* expiryDate) /* throws(CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException, InvalidAlgorithmParameterException) */;
    static ::java::security::cert::X509Certificate* generateNewCA(::java::lang::String* CN, ::java::util::Date* startDate, ::java::util::Date* expiryDate, int64_t serialNumber, ::java::security::KeyPair* keyPair, ::java::lang::String* signatureAlgorithm) /* throws(CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */;
    ::java::security::cert::X509Certificate* sign(::java::lang::String* CN, ::java::security::PublicKey* key) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */ override;
    static ::java::security::cert::X509Certificate* sign(::java::lang::String* CN, ::java::security::PublicKey* publicKey, ::java::util::Date* expiryDate, int64_t serialNumber, ::java::security::cert::X509Certificate* caCert, ::java::security::PrivateKey* privateKey) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */;
    ::java::security::cert::X509Certificate* sign(::java::lang::String* CN, ::java::security::PublicKey* publicKey, ::java::util::Date* expiryDate, int64_t serialNumber) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */ override;

private:
    static ::java::lang::String* CA_STORE_PRIVATE_;
    static ::java::lang::String* CA_STORE_PUBLIC_;
    static ::java::lang::String* CA_STORE_CERT_;

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    CAToolImpl(::java::security::cert::X509Certificate* cert, ::java::security::KeyPair* caPair);
protected:
    CAToolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* package */
    static ::java::security::SecureRandom*& random();

public:
    static ::java::lang::String*& DEFAULT_SIGNATURE_ALGORITHM();
    static ::java::lang::String*& CA_STORE_PRIVATE();
    static ::java::lang::String*& CA_STORE_PUBLIC();
    static ::java::lang::String*& CA_STORE_CERT();

private:
    virtual ::java::lang::Class* getClass0();
};
