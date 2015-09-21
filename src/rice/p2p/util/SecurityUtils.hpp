// Generated from /pastry-2.1/src/rice/p2p/util/SecurityUtils.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::SecurityUtils
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* ASYMMETRIC_ALGORITHM_;
    static ::java::lang::String* DEPRECATED_ASYMMETRIC_ALGORITHM_;
    static ::java::lang::String* SYMMETRIC_ALGORITHM_;
    static ::java::lang::String* ASYMMETRIC_GENERATOR_;
    static ::java::lang::String* SYMMETRIC_GENERATOR_;
    static ::java::lang::String* SIGNATURE_ALGORITHM_;

public:
    static constexpr int32_t SYMMETRIC_KEY_LENGTH { int32_t(56) };
    static constexpr int32_t SYMMETRIC_IV_LENGTH { int32_t(64) };

private:
    static ::java::lang::String* HASH_ALGORITHM_;
    static ::java::lang::String* HMAC_ALGORITHM_;
    static ::java::lang::String* APOP_ALGORITHM_;

public:
    static constexpr int32_t HMAC_KEY_LENGTH { int32_t(64) };
    static constexpr int8_t HMAC_IPAD_BYTE { int8_t(54) };
    static constexpr int8_t HMAC_OPAD_BYTE { int8_t(92) };

private:
    static ::int8_tArray* HMAC_IPAD_;
    static ::int8_tArray* HMAC_OPAD_;
    static ::java::security::MessageDigest* hash__;
    static ::java::security::MessageDigest* apop__;
    static ::java::security::MessageDigest* hmac1_;
    static ::java::security::MessageDigest* hmac2_;
    static ::javax::crypto::Cipher* cipherSymmetric_;
    static ::javax::crypto::Cipher* cipherAsymmetric_;
    static ::javax::crypto::Cipher* deprecatedCipherAsymmetric_;
    static ::javax::crypto::KeyGenerator* generatorSymmetric_;
    static ::java::security::KeyPairGenerator* generatorAsymmetric_;
    static ::java::security::KeyFactory* factoryAsymmetric_;
    static ::java::security::Signature* signature_;
    static ::java::util::Random* random_;
protected:
    void ctor();

public:
    static ::int8_tArray* serialize(::java::lang::Object* o) /* throws(IOException) */;
    static ::java::lang::Object* deserialize(::int8_tArray* data) /* throws(IOException, ClassNotFoundException) */;
    static ::int8_tArray* hash(::int8_tArray* input) /* throws(SecurityException) */;
    static ::int8_tArray* apop(::int8_tArray* challenge, ::int8_tArray* password) /* throws(SecurityException) */;
    static ::int8_tArray* hmac(::int8_tArray* key, ::int8_tArray* text) /* throws(SecurityException) */;
    static ::int8_tArray* encryptSymmetric(::int8_tArray* data, ::int8_tArray* key) /* throws(SecurityException) */;
    static ::int8_tArray* encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, ::int8_tArray* iv) /* throws(SecurityException) */;
    static ::int8_tArray* encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, int32_t offset, int32_t length) /* throws(SecurityException) */;
    static ::int8_tArray* encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, int32_t offset, int32_t length, ::int8_tArray* iv) /* throws(SecurityException) */;
    static ::int8_tArray* decryptSymmetric(::int8_tArray* data, ::int8_tArray* key) /* throws(SecurityException) */;
    static ::int8_tArray* decryptSymmetric(::int8_tArray* data, ::int8_tArray* key, ::int8_tArray* iv) /* throws(SecurityException) */;
    static ::int8_tArray* sign(::int8_tArray* data, ::java::security::PrivateKey* key) /* throws(SecurityException) */;
    static bool verify(::int8_tArray* data, ::int8_tArray* sig, ::java::security::PublicKey* key) /* throws(SecurityException) */;
    static ::int8_tArray* encryptAsymmetric(::int8_tArray* data, ::java::security::PublicKey* key) /* throws(SecurityException) */;
    static ::int8_tArray* decryptAsymmetric(::int8_tArray* data, ::java::security::PrivateKey* key) /* throws(SecurityException) */;
    static ::int8_tArray* generateKeySymmetric();
    static ::int8_tArray* encodePublicKey(::java::security::PublicKey* key);
    static ::java::security::PublicKey* decodePublicKey(::int8_tArray* data) /* throws(SecurityException) */;
    static ::int8_tArray* encodePrivateKey(::java::security::PrivateKey* key);
    static ::java::security::PrivateKey* decodePrivateKey(::int8_tArray* data) /* throws(SecurityException) */;
    static ::int8_tArray* generateIVSymmetric();
    static ::java::security::KeyPair* generateKeyAsymmetric();

private:
    static ::int8_tArray* correctLength(::int8_tArray* data, int32_t length);

    // Generated
    SecurityUtils();
protected:
    SecurityUtils(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& ASYMMETRIC_ALGORITHM();
    static ::java::lang::String*& DEPRECATED_ASYMMETRIC_ALGORITHM();
    static ::java::lang::String*& SYMMETRIC_ALGORITHM();
    static ::java::lang::String*& ASYMMETRIC_GENERATOR();
    static ::java::lang::String*& SYMMETRIC_GENERATOR();
    static ::java::lang::String*& SIGNATURE_ALGORITHM();
    static ::java::lang::String*& HASH_ALGORITHM();
    static ::java::lang::String*& HMAC_ALGORITHM();
    static ::java::lang::String*& APOP_ALGORITHM();
    static ::int8_tArray*& HMAC_IPAD();
    static ::int8_tArray*& HMAC_OPAD();

private:
    static ::java::security::MessageDigest*& hash_();
    static ::java::security::MessageDigest*& apop_();
    static ::java::security::MessageDigest*& hmac1();
    static ::java::security::MessageDigest*& hmac2();
    static ::javax::crypto::Cipher*& cipherSymmetric();
    static ::javax::crypto::Cipher*& cipherAsymmetric();
    static ::javax::crypto::Cipher*& deprecatedCipherAsymmetric();
    static ::javax::crypto::KeyGenerator*& generatorSymmetric();
    static ::java::security::KeyPairGenerator*& generatorAsymmetric();
    static ::java::security::KeyFactory*& factoryAsymmetric();
    static ::java::security::Signature*& signature();
    static ::java::util::Random*& random();
    virtual ::java::lang::Class* getClass0();
};
