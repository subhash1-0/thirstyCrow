// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

class javax::crypto::Cipher
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* ATTR_MODE_;
    static ::java::lang::String* ATTR_PAD_;

public:
    static constexpr int32_t DECRYPT_MODE { int32_t(2) };
    static constexpr int32_t ENCRYPT_MODE { int32_t(1) };

private:
    static constexpr int32_t I_CERT { int32_t(4) };
    static constexpr int32_t I_KEY { int32_t(1) };
    static constexpr int32_t I_PARAMS { int32_t(3) };
    static constexpr int32_t I_PARAMSPEC { int32_t(2) };
    static ::java::lang::String* KEY_USAGE_EXTENSION_OID_;

public:
    static constexpr int32_t PRIVATE_KEY { int32_t(2) };
    static constexpr int32_t PUBLIC_KEY { int32_t(1) };
    static constexpr int32_t SECRET_KEY { int32_t(3) };

private:
    static constexpr int32_t S_MAYBE { int32_t(1) };
    static constexpr int32_t S_NO { int32_t(0) };
    static constexpr int32_t S_YES { int32_t(2) };

public:
    static constexpr int32_t UNWRAP_MODE { int32_t(4) };
    static constexpr int32_t WRAP_MODE { int32_t(3) };

private:
    CryptoPermission* cryptoPerm {  };
    static ::sun::security::util::Debug* debug_;
    ExemptionMechanism* exmech {  };
    ::java::security::Provider_Service* firstService {  };
    CipherSpi* firstSpi {  };
    bool initialized {  };
    ::java::lang::Object* lock {  };
    int32_t opmode {  };
    static ::sun::security::util::Debug* pdebug_;
    ::java::security::Provider* provider {  };
    ::java::util::Iterator* serviceIterator {  };
    static bool skipDebug_;
    CipherSpi* spi {  };
    ::java::lang::String* transformation {  };
    ::java::util::List* transforms {  };
    static int32_t warnCount_;

protected:
    void ctor(CipherSpi* arg0, ::java::lang::String* arg1);
    void ctor(CipherSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
    /*void ctor(CipherSpi* arg0, ::java::security::Provider_Service* arg1, ::java::util::Iterator* arg2, ::java::lang::String* arg3, ::java::util::List* arg4); (private) */
    /*void checkCipherState(); (private) */
    /*void checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1); (private) */
    /*void checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2); (private) */
    /*void checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2); (private) */
    /*static void checkOpmode(int32_t arg0); (private) */

public: /* package */
    virtual void chooseFirstProvider();
    /*void chooseProvider(int32_t arg0, int32_t arg1, ::java::security::Key* arg2, ::java::security::spec::AlgorithmParameterSpec* arg3, ::java::security::AlgorithmParameters* arg4, ::java::security::SecureRandom* arg5); (private) */

public:
    ::int8_tArray* doFinal();
    ::int8_tArray* doFinal(::int8_tArray* arg0);
    int32_t doFinal(::int8_tArray* arg0, int32_t arg1);
    int32_t doFinal(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1);
    ::int8_tArray* doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    int32_t doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3);
    int32_t doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4);
    ::java::lang::String* getAlgorithm();
    /*::java::security::spec::AlgorithmParameterSpec* getAlgorithmParameterSpec(::java::security::AlgorithmParameters* arg0); (private) */
    int32_t getBlockSize();
    /*static CryptoPermission* getConfiguredPermission(::java::lang::String* arg0); (private) */
    ExemptionMechanism* getExemptionMechanism();
    ::int8_tArray* getIV();
    static Cipher* getInstance(::java::lang::String* arg0);
    static Cipher* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static Cipher* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    static int32_t getMaxAllowedKeyLength(::java::lang::String* arg0);
    static ::java::security::spec::AlgorithmParameterSpec* getMaxAllowedParameterSpec(::java::lang::String* arg0);
    /*static ::java::lang::String* getOpmodeString(int32_t arg0); (private) */
    int32_t getOutputSize(int32_t arg0);
    ::java::security::AlgorithmParameters* getParameters();
    ::java::security::Provider* getProvider();
    /*static Cipher_Transform* getTransform(::java::security::Provider_Service* arg0, ::java::util::List* arg1); (private) */
    /*static ::java::util::List* getTransforms(::java::lang::String* arg0); (private) */
    /*void implInit(CipherSpi* arg0, int32_t arg1, int32_t arg2, ::java::security::Key* arg3, ::java::security::spec::AlgorithmParameterSpec* arg4, ::java::security::AlgorithmParameters* arg5, ::java::security::SecureRandom* arg6); (private) */
    void init_(int32_t arg0, ::java::security::Key* arg1);
    void init_(int32_t arg0, ::java::security::cert::Certificate* arg1);
    void init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::SecureRandom* arg2);
    void init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2);
    void init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2);
    void init_(int32_t arg0, ::java::security::cert::Certificate* arg1, ::java::security::SecureRandom* arg2);
    void init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2, ::java::security::SecureRandom* arg3);
    void init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2, ::java::security::SecureRandom* arg3);
    /*void initCryptoPermission(); (private) */
    /*bool passCryptoPermCheck(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2); (private) */
    /*static ::java::lang::StringArray* tokenizeTransformation(::java::lang::String* arg0); (private) */
    ::java::security::Key* unwrap(::int8_tArray* arg0, ::java::lang::String* arg1, int32_t arg2);
    ::int8_tArray* update(::int8_tArray* arg0);
    int32_t update(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1);
    ::int8_tArray* update(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    int32_t update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3);
    int32_t update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4);
    void updateAAD(::int8_tArray* arg0);
    void updateAAD(::java::nio::ByteBuffer* arg0);
    void updateAAD(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    ::int8_tArray* wrap(::java::security::Key* arg0);

    // Generated

public: /* package */
    Cipher(CipherSpi* arg0, ::java::lang::String* arg1);

public: /* protected */
    Cipher(CipherSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    Cipher(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::lang::String*& ATTR_MODE();
    static ::java::lang::String*& ATTR_PAD();
    static ::java::lang::String*& KEY_USAGE_EXTENSION_OID();
    static ::sun::security::util::Debug*& debug();
    static ::sun::security::util::Debug*& pdebug();
    static bool& skipDebug();
    static int32_t& warnCount();
    virtual ::java::lang::Class* getClass0();
};
