// Generated from /pastry-2.1/src/rice/p2p/util/SecurityUtils.java
#include <rice/p2p/util/SecurityUtils.hpp>

#include <java/io/BufferedInputStream.hpp>
#include <java/io/BufferedOutputStream.hpp>
#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/SecurityException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/math/BigInteger.hpp>
#include <java/security/InvalidAlgorithmParameterException.hpp>
#include <java/security/InvalidKeyException.hpp>
#include <java/security/Key.hpp>
#include <java/security/KeyFactory.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/KeyPairGenerator.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <java/security/NoSuchProviderException.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/PublicKey.hpp>
#include <java/security/Security.hpp>
#include <java/security/Signature.hpp>
#include <java/security/SignatureException.hpp>
#include <java/security/interfaces/RSAPrivateKey.hpp>
#include <java/security/interfaces/RSAPublicKey.hpp>
#include <java/security/spec/AlgorithmParameterSpec.hpp>
#include <java/security/spec/InvalidKeySpecException.hpp>
#include <java/security/spec/RSAPrivateKeySpec.hpp>
#include <java/security/spec/RSAPublicKeySpec.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Random.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <javax/crypto/BadPaddingException.hpp>
#include <javax/crypto/Cipher.hpp>
#include <javax/crypto/IllegalBlockSizeException.hpp>
#include <javax/crypto/KeyGenerator.hpp>
#include <javax/crypto/NoSuchPaddingException.hpp>
#include <javax/crypto/SecretKey.hpp>
#include <javax/crypto/spec/IvParameterSpec.hpp>
#include <javax/crypto/spec/SecretKeySpec.hpp>
#include <org/bouncycastle/jce/provider/BouncyCastleProvider.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::p2p::util::SecurityUtils::SecurityUtils(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::SecurityUtils::SecurityUtils() 
    : SecurityUtils(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::String*& rice::p2p::util::SecurityUtils::ASYMMETRIC_ALGORITHM()
{
    clinit();
    return ASYMMETRIC_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::ASYMMETRIC_ALGORITHM_;

java::lang::String*& rice::p2p::util::SecurityUtils::DEPRECATED_ASYMMETRIC_ALGORITHM()
{
    clinit();
    return DEPRECATED_ASYMMETRIC_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::DEPRECATED_ASYMMETRIC_ALGORITHM_;

java::lang::String*& rice::p2p::util::SecurityUtils::SYMMETRIC_ALGORITHM()
{
    clinit();
    return SYMMETRIC_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::SYMMETRIC_ALGORITHM_;

java::lang::String*& rice::p2p::util::SecurityUtils::ASYMMETRIC_GENERATOR()
{
    clinit();
    return ASYMMETRIC_GENERATOR_;
}
java::lang::String* rice::p2p::util::SecurityUtils::ASYMMETRIC_GENERATOR_;

java::lang::String*& rice::p2p::util::SecurityUtils::SYMMETRIC_GENERATOR()
{
    clinit();
    return SYMMETRIC_GENERATOR_;
}
java::lang::String* rice::p2p::util::SecurityUtils::SYMMETRIC_GENERATOR_;

java::lang::String*& rice::p2p::util::SecurityUtils::SIGNATURE_ALGORITHM()
{
    clinit();
    return SIGNATURE_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::SIGNATURE_ALGORITHM_;

constexpr int32_t rice::p2p::util::SecurityUtils::SYMMETRIC_KEY_LENGTH;

constexpr int32_t rice::p2p::util::SecurityUtils::SYMMETRIC_IV_LENGTH;

java::lang::String*& rice::p2p::util::SecurityUtils::HASH_ALGORITHM()
{
    clinit();
    return HASH_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::HASH_ALGORITHM_;

java::lang::String*& rice::p2p::util::SecurityUtils::HMAC_ALGORITHM()
{
    clinit();
    return HMAC_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::HMAC_ALGORITHM_;

java::lang::String*& rice::p2p::util::SecurityUtils::APOP_ALGORITHM()
{
    clinit();
    return APOP_ALGORITHM_;
}
java::lang::String* rice::p2p::util::SecurityUtils::APOP_ALGORITHM_;

constexpr int32_t rice::p2p::util::SecurityUtils::HMAC_KEY_LENGTH;

constexpr int8_t rice::p2p::util::SecurityUtils::HMAC_IPAD_BYTE;

constexpr int8_t rice::p2p::util::SecurityUtils::HMAC_OPAD_BYTE;

int8_tArray*& rice::p2p::util::SecurityUtils::HMAC_IPAD()
{
    clinit();
    return HMAC_IPAD_;
}
int8_tArray* rice::p2p::util::SecurityUtils::HMAC_IPAD_;

int8_tArray*& rice::p2p::util::SecurityUtils::HMAC_OPAD()
{
    clinit();
    return HMAC_OPAD_;
}
int8_tArray* rice::p2p::util::SecurityUtils::HMAC_OPAD_;

java::security::MessageDigest*& rice::p2p::util::SecurityUtils::hash_()
{
    clinit();
    return hash__;
}
java::security::MessageDigest* rice::p2p::util::SecurityUtils::hash__;

java::security::MessageDigest*& rice::p2p::util::SecurityUtils::apop_()
{
    clinit();
    return apop__;
}
java::security::MessageDigest* rice::p2p::util::SecurityUtils::apop__;

java::security::MessageDigest*& rice::p2p::util::SecurityUtils::hmac1()
{
    clinit();
    return hmac1_;
}
java::security::MessageDigest* rice::p2p::util::SecurityUtils::hmac1_;

java::security::MessageDigest*& rice::p2p::util::SecurityUtils::hmac2()
{
    clinit();
    return hmac2_;
}
java::security::MessageDigest* rice::p2p::util::SecurityUtils::hmac2_;

javax::crypto::Cipher*& rice::p2p::util::SecurityUtils::cipherSymmetric()
{
    clinit();
    return cipherSymmetric_;
}
javax::crypto::Cipher* rice::p2p::util::SecurityUtils::cipherSymmetric_;

javax::crypto::Cipher*& rice::p2p::util::SecurityUtils::cipherAsymmetric()
{
    clinit();
    return cipherAsymmetric_;
}
javax::crypto::Cipher* rice::p2p::util::SecurityUtils::cipherAsymmetric_;

javax::crypto::Cipher*& rice::p2p::util::SecurityUtils::deprecatedCipherAsymmetric()
{
    clinit();
    return deprecatedCipherAsymmetric_;
}
javax::crypto::Cipher* rice::p2p::util::SecurityUtils::deprecatedCipherAsymmetric_;

javax::crypto::KeyGenerator*& rice::p2p::util::SecurityUtils::generatorSymmetric()
{
    clinit();
    return generatorSymmetric_;
}
javax::crypto::KeyGenerator* rice::p2p::util::SecurityUtils::generatorSymmetric_;

java::security::KeyPairGenerator*& rice::p2p::util::SecurityUtils::generatorAsymmetric()
{
    clinit();
    return generatorAsymmetric_;
}
java::security::KeyPairGenerator* rice::p2p::util::SecurityUtils::generatorAsymmetric_;

java::security::KeyFactory*& rice::p2p::util::SecurityUtils::factoryAsymmetric()
{
    clinit();
    return factoryAsymmetric_;
}
java::security::KeyFactory* rice::p2p::util::SecurityUtils::factoryAsymmetric_;

java::security::Signature*& rice::p2p::util::SecurityUtils::signature()
{
    clinit();
    return signature_;
}
java::security::Signature* rice::p2p::util::SecurityUtils::signature_;

java::util::Random*& rice::p2p::util::SecurityUtils::random()
{
    clinit();
    return random_;
}
java::util::Random* rice::p2p::util::SecurityUtils::random_;

void rice::p2p::util::SecurityUtils::ctor()
{
    super::ctor();
}

int8_tArray* rice::p2p::util::SecurityUtils::serialize(::java::lang::Object* o) /* throws(IOException) */
{
    clinit();
    auto baos = new ::java::io::ByteArrayOutputStream();
    ::java::io::ObjectOutputStream* oos = new XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(baos)));
    npc(oos)->writeObject(o);
    npc(oos)->flush();
    npc(oos)->close();
    return npc(baos)->toByteArray_();
}

java::lang::Object* rice::p2p::util::SecurityUtils::deserialize(::int8_tArray* data) /* throws(IOException, ClassNotFoundException) */
{
    clinit();
    auto bais = new ::java::io::ByteArrayInputStream(data);
    ::java::io::ObjectInputStream* ois = new XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(bais)));
    return npc(ois)->readObject();
}

int8_tArray* rice::p2p::util::SecurityUtils::hash(::int8_tArray* input) /* throws(SecurityException) */
{
    clinit();
    {
        synchronized synchronized_0(hash__);
        {
            return npc(hash__)->digest(input);
        }
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::apop(::int8_tArray* challenge, ::int8_tArray* password) /* throws(SecurityException) */
{
    clinit();
    {
        synchronized synchronized_1(apop__);
        {
            npc(apop__)->update(challenge);
            npc(apop__)->update(password);
            return npc(apop__)->digest();
        }
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::hmac(::int8_tArray* key, ::int8_tArray* text) /* throws(SecurityException) */
{
    clinit();
    {
        synchronized synchronized_2(hmac1_);
        {
            auto realKey = new ::int8_tArray(HMAC_KEY_LENGTH);
            ::java::lang::System::arraycopy(key, 0, realKey, 0, (npc(key)->length < npc(realKey)->length ? npc(key)->length : npc(realKey)->length));
            npc(hmac1_)->update(MathUtils::xor_(realKey, HMAC_IPAD_));
            npc(hmac1_)->update(text);
            npc(hmac2_)->update(MathUtils::xor_(realKey, HMAC_OPAD_));
            npc(hmac2_)->update(npc(hmac1_)->digest());
            return npc(hmac2_)->digest();
        }
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::encryptSymmetric(::int8_tArray* data, ::int8_tArray* key) /* throws(SecurityException) */
{
    clinit();
    return encryptSymmetric(data, key, new ::int8_tArray(SYMMETRIC_IV_LENGTH));
}

int8_tArray* rice::p2p::util::SecurityUtils::encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, ::int8_tArray* iv) /* throws(SecurityException) */
{
    clinit();
    return encryptSymmetric(data, key, 0, npc(data)->length, iv);
}

int8_tArray* rice::p2p::util::SecurityUtils::encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, int32_t offset, int32_t length) /* throws(SecurityException) */
{
    clinit();
    return encryptSymmetric(data, key, offset, length, new ::int8_tArray(SYMMETRIC_IV_LENGTH));
}

int8_tArray* rice::p2p::util::SecurityUtils::encryptSymmetric(::int8_tArray* data, ::int8_tArray* key, int32_t offset, int32_t length, ::int8_tArray* iv) /* throws(SecurityException) */
{
    clinit();
    try {
        iv = correctLength(iv, SYMMETRIC_IV_LENGTH / int32_t(8));
        auto ivSpec = new ::javax::crypto::spec::IvParameterSpec(iv);
        auto secretKey = new ::javax::crypto::spec::SecretKeySpec(key, SYMMETRIC_ALGORITHM_);
        {
            synchronized synchronized_3(cipherSymmetric_);
            {
                npc(cipherSymmetric_)->init_(::javax::crypto::Cipher::ENCRYPT_MODE, static_cast< ::java::security::Key* >(secretKey), static_cast< ::java::security::spec::AlgorithmParameterSpec* >(ivSpec));
                return npc(cipherSymmetric_)->doFinal(data, offset, length);
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException ("_j)->append(npc(iv)->length)
            ->append(u","_j)
            ->append(npc(key)->length)
            ->append(u") encrypting object: "_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::IllegalBlockSizeException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"IllegalBlockSizeException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::BadPaddingException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"BadPaddingException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::java::security::InvalidAlgorithmParameterException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidAlgorithmParameterException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::decryptSymmetric(::int8_tArray* data, ::int8_tArray* key) /* throws(SecurityException) */
{
    clinit();
    return decryptSymmetric(data, key, new ::int8_tArray(SYMMETRIC_IV_LENGTH));
}

int8_tArray* rice::p2p::util::SecurityUtils::decryptSymmetric(::int8_tArray* data, ::int8_tArray* key, ::int8_tArray* iv) /* throws(SecurityException) */
{
    clinit();
    try {
        iv = correctLength(iv, SYMMETRIC_IV_LENGTH / int32_t(8));
        auto ivSpec = new ::javax::crypto::spec::IvParameterSpec(iv);
        auto secretKey = new ::javax::crypto::spec::SecretKeySpec(key, SYMMETRIC_ALGORITHM_);
        {
            synchronized synchronized_4(cipherSymmetric_);
            {
                npc(cipherSymmetric_)->init_(::javax::crypto::Cipher::DECRYPT_MODE, static_cast< ::java::security::Key* >(secretKey), static_cast< ::java::security::spec::AlgorithmParameterSpec* >(ivSpec));
                return npc(cipherSymmetric_)->doFinal(data);
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::IllegalBlockSizeException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"IllegalBlockSizeException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::BadPaddingException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"BadPaddingException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::java::security::InvalidAlgorithmParameterException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidAlgorithmParameterException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::sign(::int8_tArray* data, ::java::security::PrivateKey* key) /* throws(SecurityException) */
{
    clinit();
    try {
        {
            synchronized synchronized_5(signature_);
            {
                npc(signature_)->initSign(key);
                npc(signature_)->update(hash(data));
                return npc(signature_)->sign();
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException signing object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::java::security::SignatureException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"SignatureException signing object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

bool rice::p2p::util::SecurityUtils::verify(::int8_tArray* data, ::int8_tArray* sig, ::java::security::PublicKey* key) /* throws(SecurityException) */
{
    clinit();
    try {
        {
            synchronized synchronized_6(signature_);
            {
                npc(signature_)->initVerify(key);
                npc(signature_)->update(hash(data));
                return npc(signature_)->verify(sig);
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException verifying object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::java::security::SignatureException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"SignatureException verifying object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::encryptAsymmetric(::int8_tArray* data, ::java::security::PublicKey* key) /* throws(SecurityException) */
{
    clinit();
    try {
        {
            synchronized synchronized_7(cipherAsymmetric_);
            {
                npc(cipherAsymmetric_)->init_(::javax::crypto::Cipher::ENCRYPT_MODE, static_cast< ::java::security::Key* >(key));
                return npc(cipherAsymmetric_)->doFinal(data);
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::IllegalBlockSizeException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"IllegalBlockSizeException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::BadPaddingException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"BadPaddingException encrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::decryptAsymmetric(::int8_tArray* data, ::java::security::PrivateKey* key) /* throws(SecurityException) */
{
    clinit();
    try {
        try {
            {
                synchronized synchronized_8(cipherAsymmetric_);
                {
                    npc(cipherAsymmetric_)->init_(::javax::crypto::Cipher::DECRYPT_MODE, static_cast< ::java::security::Key* >(key));
                    return npc(cipherAsymmetric_)->doFinal(data);
                }
            }
        } catch (::javax::crypto::BadPaddingException* e) {
            {
                synchronized synchronized_9(deprecatedCipherAsymmetric_);
                {
                    npc(deprecatedCipherAsymmetric_)->init_(::javax::crypto::Cipher::DECRYPT_MODE, static_cast< ::java::security::Key* >(key));
                    return npc(deprecatedCipherAsymmetric_)->doFinal(data);
                }
            }
        }
    } catch (::java::security::InvalidKeyException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeyException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::IllegalBlockSizeException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"IllegalBlockSizeException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    } catch (::javax::crypto::BadPaddingException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"BadPaddingException decrypting object: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::generateKeySymmetric()
{
    clinit();
    {
        synchronized synchronized_10(generatorSymmetric_);
        {
            return npc(npc(generatorSymmetric_)->generateKey())->getEncoded();
        }
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::encodePublicKey(::java::security::PublicKey* key)
{
    clinit();
    auto rkey = java_cast< ::java::security::interfaces::RSAPublicKey* >(key);
    auto modulus = npc(npc(rkey)->getModulus())->toByteArray_();
    auto exponent = npc(npc(rkey)->getPublicExponent())->toByteArray_();
    auto length = MathUtils::intToByteArray_(npc(modulus)->length);
    auto result = new ::int8_tArray(npc(length)->length + npc(modulus)->length + npc(exponent)->length);
    ::java::lang::System::arraycopy(length, 0, result, 0, npc(length)->length);
    ::java::lang::System::arraycopy(modulus, 0, result, npc(length)->length, npc(modulus)->length);
    ::java::lang::System::arraycopy(exponent, 0, result, npc(length)->length + npc(modulus)->length, npc(exponent)->length);
    return result;
}

java::security::PublicKey* rice::p2p::util::SecurityUtils::decodePublicKey(::int8_tArray* data) /* throws(SecurityException) */
{
    clinit();
    auto len = new ::int8_tArray(int32_t(4));
    ::java::lang::System::arraycopy(data, 0, len, 0, npc(len)->length);
    auto length = MathUtils::byteArrayToInt(len);
    auto modulus = new ::int8_tArray(length);
    ::java::lang::System::arraycopy(data, npc(len)->length, modulus, 0, length);
    auto exponent = new ::int8_tArray(npc(data)->length - length - int32_t(4));
    ::java::lang::System::arraycopy(data, npc(len)->length + length, exponent, 0, npc(exponent)->length);
    auto rpks = new ::java::security::spec::RSAPublicKeySpec(new ::java::math::BigInteger(modulus), new ::java::math::BigInteger(exponent));
    try {
        {
            synchronized synchronized_11(factoryAsymmetric_);
            {
                return npc(factoryAsymmetric_)->generatePublic(rpks);
            }
        }
    } catch (::java::security::spec::InvalidKeySpecException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeySpecException while decoding key: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::encodePrivateKey(::java::security::PrivateKey* key)
{
    clinit();
    auto rkey = java_cast< ::java::security::interfaces::RSAPrivateKey* >(key);
    auto modulus = npc(npc(rkey)->getModulus())->toByteArray_();
    auto exponent = npc(npc(rkey)->getPrivateExponent())->toByteArray_();
    auto length = MathUtils::intToByteArray_(npc(modulus)->length);
    auto result = new ::int8_tArray(npc(length)->length + npc(modulus)->length + npc(exponent)->length);
    ::java::lang::System::arraycopy(length, 0, result, 0, npc(length)->length);
    ::java::lang::System::arraycopy(modulus, 0, result, npc(length)->length, npc(modulus)->length);
    ::java::lang::System::arraycopy(exponent, 0, result, npc(length)->length + npc(modulus)->length, npc(exponent)->length);
    return result;
}

java::security::PrivateKey* rice::p2p::util::SecurityUtils::decodePrivateKey(::int8_tArray* data) /* throws(SecurityException) */
{
    clinit();
    auto len = new ::int8_tArray(int32_t(4));
    ::java::lang::System::arraycopy(data, 0, len, 0, npc(len)->length);
    auto length = MathUtils::byteArrayToInt(len);
    auto modulus = new ::int8_tArray(length);
    ::java::lang::System::arraycopy(data, npc(len)->length, modulus, 0, length);
    auto exponent = new ::int8_tArray(npc(data)->length - length - int32_t(4));
    ::java::lang::System::arraycopy(data, npc(len)->length + length, exponent, 0, npc(exponent)->length);
    auto rpks = new ::java::security::spec::RSAPrivateKeySpec(new ::java::math::BigInteger(modulus), new ::java::math::BigInteger(exponent));
    try {
        {
            synchronized synchronized_12(factoryAsymmetric_);
            {
                return npc(factoryAsymmetric_)->generatePrivate(rpks);
            }
        }
    } catch (::java::security::spec::InvalidKeySpecException* e) {
        throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"InvalidKeySpecException while decoding key: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::generateIVSymmetric()
{
    clinit();
    auto result = new ::int8_tArray(SYMMETRIC_IV_LENGTH);
    npc(random_)->nextBytes(result);
    return result;
}

java::security::KeyPair* rice::p2p::util::SecurityUtils::generateKeyAsymmetric()
{
    clinit();
    {
        synchronized synchronized_13(generatorAsymmetric_);
        {
            return npc(generatorAsymmetric_)->generateKeyPair();
        }
    }
}

int8_tArray* rice::p2p::util::SecurityUtils::correctLength(::int8_tArray* data, int32_t length)
{
    clinit();
    auto result = new ::int8_tArray(length);
    for (auto i = int32_t(0); (i < npc(data)->length) && (i < npc(result)->length); i++) {
        (*result)[i] = (*data)[i];
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::SecurityUtils::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.SecurityUtils", 27);
    return c;
}

void rice::p2p::util::SecurityUtils::clinit()
{
struct string_init_ {
    string_init_() {
    ASYMMETRIC_ALGORITHM_ = u"RSA/ECB/OAEPPadding"_j;
    DEPRECATED_ASYMMETRIC_ALGORITHM_ = u"RSA"_j;
    SYMMETRIC_ALGORITHM_ = u"DES"_j;
    ASYMMETRIC_GENERATOR_ = u"RSA"_j;
    SYMMETRIC_GENERATOR_ = u"DES"_j;
    SIGNATURE_ALGORITHM_ = u"SHA1withRSA"_j;
    HASH_ALGORITHM_ = u"SHA1"_j;
    HMAC_ALGORITHM_ = u"MD5"_j;
    APOP_ALGORITHM_ = u"MD5"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        HMAC_IPAD_ = new ::int8_tArray(HMAC_KEY_LENGTH);
        HMAC_OPAD_ = new ::int8_tArray(HMAC_KEY_LENGTH);
        {
            ::java::util::Arrays::fill(HMAC_IPAD_, HMAC_IPAD_BYTE);
            ::java::util::Arrays::fill(HMAC_OPAD_, HMAC_OPAD_BYTE);
        }
        {
            ::java::security::Security::insertProviderAt(new ::org::bouncycastle::jce::provider::BouncyCastleProvider(), 2);
            try {
                random_ = new ::java::util::Random();
                cipherSymmetric_ = ::javax::crypto::Cipher::getInstance(SYMMETRIC_ALGORITHM_);
                cipherAsymmetric_ = ::javax::crypto::Cipher::getInstance(ASYMMETRIC_ALGORITHM_, u"BC"_j);
                deprecatedCipherAsymmetric_ = ::javax::crypto::Cipher::getInstance(DEPRECATED_ASYMMETRIC_ALGORITHM_);
                generatorSymmetric_ = ::javax::crypto::KeyGenerator::getInstance(SYMMETRIC_GENERATOR_);
                generatorAsymmetric_ = ::java::security::KeyPairGenerator::getInstance(ASYMMETRIC_GENERATOR_);
                factoryAsymmetric_ = ::java::security::KeyFactory::getInstance(ASYMMETRIC_GENERATOR_);
                signature_ = ::java::security::Signature::getInstance(SIGNATURE_ALGORITHM_);
                hash__ = ::java::security::MessageDigest::getInstance(HASH_ALGORITHM_);
                apop__ = ::java::security::MessageDigest::getInstance(APOP_ALGORITHM_);
                hmac1_ = ::java::security::MessageDigest::getInstance(HMAC_ALGORITHM_);
                hmac2_ = ::java::security::MessageDigest::getInstance(HMAC_ALGORITHM_);
                npc(generatorSymmetric_)->init_(SYMMETRIC_KEY_LENGTH);
            } catch (::java::security::NoSuchAlgorithmException* e) {
                throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"NoSuchAlgorithmException on construction: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            } catch (::javax::crypto::NoSuchPaddingException* e) {
                throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"NoSuchPaddingException on construction: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            } catch (::java::security::NoSuchProviderException* e) {
                throw new ::java::lang::SecurityException(::java::lang::StringBuilder().append(u"NoSuchProviderException on construction: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
            }
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::SecurityUtils::getClass0()
{
    return class_();
}

