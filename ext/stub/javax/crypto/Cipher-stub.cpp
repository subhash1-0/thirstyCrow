// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar
#include <javax/crypto/Cipher.hpp>

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

extern void unimplemented_(const char16_t* name);
javax::crypto::Cipher::Cipher(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::crypto::Cipher::Cipher(CipherSpi* arg0, ::java::lang::String* arg1)
    : Cipher(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

javax::crypto::Cipher::Cipher(CipherSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : Cipher(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::lang::String*& javax::crypto::Cipher::ATTR_MODE()
{
    clinit();
    return ATTR_MODE_;
}
java::lang::String* javax::crypto::Cipher::ATTR_MODE_;
java::lang::String*& javax::crypto::Cipher::ATTR_PAD()
{
    clinit();
    return ATTR_PAD_;
}
java::lang::String* javax::crypto::Cipher::ATTR_PAD_;
constexpr int32_t javax::crypto::Cipher::DECRYPT_MODE;
constexpr int32_t javax::crypto::Cipher::ENCRYPT_MODE;
constexpr int32_t javax::crypto::Cipher::I_CERT;
constexpr int32_t javax::crypto::Cipher::I_KEY;
constexpr int32_t javax::crypto::Cipher::I_PARAMS;
constexpr int32_t javax::crypto::Cipher::I_PARAMSPEC;
java::lang::String*& javax::crypto::Cipher::KEY_USAGE_EXTENSION_OID()
{
    clinit();
    return KEY_USAGE_EXTENSION_OID_;
}
java::lang::String* javax::crypto::Cipher::KEY_USAGE_EXTENSION_OID_;
constexpr int32_t javax::crypto::Cipher::PRIVATE_KEY;
constexpr int32_t javax::crypto::Cipher::PUBLIC_KEY;
constexpr int32_t javax::crypto::Cipher::SECRET_KEY;
constexpr int32_t javax::crypto::Cipher::S_MAYBE;
constexpr int32_t javax::crypto::Cipher::S_NO;
constexpr int32_t javax::crypto::Cipher::S_YES;
constexpr int32_t javax::crypto::Cipher::UNWRAP_MODE;
constexpr int32_t javax::crypto::Cipher::WRAP_MODE;
sun::security::util::Debug*& javax::crypto::Cipher::debug()
{
    clinit();
    return debug_;
}
sun::security::util::Debug* javax::crypto::Cipher::debug_;
sun::security::util::Debug*& javax::crypto::Cipher::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* javax::crypto::Cipher::pdebug_;
bool& javax::crypto::Cipher::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool javax::crypto::Cipher::skipDebug_;
int32_t& javax::crypto::Cipher::warnCount()
{
    clinit();
    return warnCount_;
}
int32_t javax::crypto::Cipher::warnCount_;

void ::javax::crypto::Cipher::ctor(CipherSpi* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::Cipher::ctor(CipherSpi* arg0, ::java::lang::String* arg1)");
}

void ::javax::crypto::Cipher::ctor(CipherSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::Cipher::ctor(CipherSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

/* private: void ::javax::crypto::Cipher::ctor(CipherSpi* arg0, ::java::security::Provider_Service* arg1, ::java::util::Iterator* arg2, ::java::lang::String* arg3, ::java::util::List* arg4) */
/* private: void javax::crypto::Cipher::checkCipherState() */
/* private: void javax::crypto::Cipher::checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1) */
/* private: void javax::crypto::Cipher::checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2) */
/* private: void javax::crypto::Cipher::checkCryptoPerm(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2) */
/* private: void javax::crypto::Cipher::checkOpmode(int32_t arg0) */
void javax::crypto::Cipher::chooseFirstProvider()
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::chooseFirstProvider()");
}

/* private: void javax::crypto::Cipher::chooseProvider(int32_t arg0, int32_t arg1, ::java::security::Key* arg2, ::java::security::spec::AlgorithmParameterSpec* arg3, ::java::security::AlgorithmParameters* arg4, ::java::security::SecureRandom* arg5) */
int8_tArray* javax::crypto::Cipher::doFinal()
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::doFinal()");
    return 0;
}

int8_tArray* javax::crypto::Cipher::doFinal(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::doFinal(::int8_tArray* arg0)");
    return 0;
}

int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1)");
    return 0;
}

int32_t javax::crypto::Cipher::doFinal(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::doFinal(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)");
    return 0;
}

int8_tArray* javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3)");
    return 0;
}

int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::doFinal(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4)");
    return 0;
}

java::lang::String* javax::crypto::Cipher::getAlgorithm()
{ /* stub */
    unimplemented_(u"java::lang::String* javax::crypto::Cipher::getAlgorithm()");
    return 0;
}

/* private: java::security::spec::AlgorithmParameterSpec* javax::crypto::Cipher::getAlgorithmParameterSpec(::java::security::AlgorithmParameters* arg0) */
int32_t javax::crypto::Cipher::getBlockSize()
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::getBlockSize()");
    return 0;
}

/* private: javax::crypto::CryptoPermission* javax::crypto::Cipher::getConfiguredPermission(::java::lang::String* arg0) */
javax::crypto::ExemptionMechanism* javax::crypto::Cipher::getExemptionMechanism()
{ /* stub */
    unimplemented_(u"javax::crypto::ExemptionMechanism* javax::crypto::Cipher::getExemptionMechanism()");
    return 0;
}

int8_tArray* javax::crypto::Cipher::getIV()
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::getIV()");
    return 0;
}

javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0)");
    return 0;
}

javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::Cipher* javax::crypto::Cipher::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

int32_t javax::crypto::Cipher::getMaxAllowedKeyLength(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t javax::crypto::Cipher::getMaxAllowedKeyLength(::java::lang::String* arg0)");
    return 0;
}

java::security::spec::AlgorithmParameterSpec* javax::crypto::Cipher::getMaxAllowedParameterSpec(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::spec::AlgorithmParameterSpec* javax::crypto::Cipher::getMaxAllowedParameterSpec(::java::lang::String* arg0)");
    return 0;
}

/* private: java::lang::String* javax::crypto::Cipher::getOpmodeString(int32_t arg0) */
int32_t javax::crypto::Cipher::getOutputSize(int32_t arg0)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::getOutputSize(int32_t arg0)");
    return 0;
}

java::security::AlgorithmParameters* javax::crypto::Cipher::getParameters()
{ /* stub */
    unimplemented_(u"java::security::AlgorithmParameters* javax::crypto::Cipher::getParameters()");
    return 0;
}

java::security::Provider* javax::crypto::Cipher::getProvider()
{ /* stub */
return provider ; /* getter */
}

/* private: javax::crypto::Cipher_Transform* javax::crypto::Cipher::getTransform(::java::security::Provider_Service* arg0, ::java::util::List* arg1) */
/* private: java::util::List* javax::crypto::Cipher::getTransforms(::java::lang::String* arg0) */
/* private: void javax::crypto::Cipher::implInit(CipherSpi* arg0, int32_t arg1, int32_t arg2, ::java::security::Key* arg3, ::java::security::spec::AlgorithmParameterSpec* arg4, ::java::security::AlgorithmParameters* arg5, ::java::security::SecureRandom* arg6) */
void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::cert::Certificate* arg1)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::cert::Certificate* arg1)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::SecureRandom* arg2)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::SecureRandom* arg2)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::cert::Certificate* arg1, ::java::security::SecureRandom* arg2)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::cert::Certificate* arg1, ::java::security::SecureRandom* arg2)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2, ::java::security::SecureRandom* arg3)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2, ::java::security::SecureRandom* arg3)");
}

void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2, ::java::security::SecureRandom* arg3)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::init_(int32_t arg0, ::java::security::Key* arg1, ::java::security::AlgorithmParameters* arg2, ::java::security::SecureRandom* arg3)");
}

/* private: void javax::crypto::Cipher::initCryptoPermission() */
/* private: bool javax::crypto::Cipher::passCryptoPermCheck(CipherSpi* arg0, ::java::security::Key* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2) */
/* private: java::lang::StringArray* javax::crypto::Cipher::tokenizeTransformation(::java::lang::String* arg0) */
java::security::Key* javax::crypto::Cipher::unwrap(::int8_tArray* arg0, ::java::lang::String* arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"java::security::Key* javax::crypto::Cipher::unwrap(::int8_tArray* arg0, ::java::lang::String* arg1, int32_t arg2)");
    return 0;
}

int8_tArray* javax::crypto::Cipher::update(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::update(::int8_tArray* arg0)");
    return 0;
}

int32_t javax::crypto::Cipher::update(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::update(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)");
    return 0;
}

int8_tArray* javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

int32_t javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3)");
    return 0;
}

int32_t javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::int8_tArray* arg3, int32_t arg4)");
    return 0;
}

void javax::crypto::Cipher::updateAAD(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::updateAAD(::int8_tArray* arg0)");
}

void javax::crypto::Cipher::updateAAD(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::updateAAD(::java::nio::ByteBuffer* arg0)");
}

void javax::crypto::Cipher::updateAAD(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher::updateAAD(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

int8_tArray* javax::crypto::Cipher::wrap(::java::security::Key* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::Cipher::wrap(::java::security::Key* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::crypto::Cipher::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.crypto.Cipher", 19);
    return c;
}

java::lang::Class* javax::crypto::Cipher::getClass0()
{
    return class_();
}

