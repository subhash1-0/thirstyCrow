// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar
#include <javax/crypto/KeyGenerator.hpp>

extern void unimplemented_(const char16_t* name);
javax::crypto::KeyGenerator::KeyGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::crypto::KeyGenerator::KeyGenerator(KeyGeneratorSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : KeyGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int32_t javax::crypto::KeyGenerator::I_NONE;
constexpr int32_t javax::crypto::KeyGenerator::I_PARAMS;
constexpr int32_t javax::crypto::KeyGenerator::I_RANDOM;
constexpr int32_t javax::crypto::KeyGenerator::I_SIZE;
sun::security::util::Debug*& javax::crypto::KeyGenerator::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* javax::crypto::KeyGenerator::pdebug_;
bool& javax::crypto::KeyGenerator::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool javax::crypto::KeyGenerator::skipDebug_;

/* private: void ::javax::crypto::KeyGenerator::ctor(::java::lang::String* arg0) */
void ::javax::crypto::KeyGenerator::ctor(KeyGeneratorSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::KeyGenerator::ctor(KeyGeneratorSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

void javax::crypto::KeyGenerator::disableFailover()
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::disableFailover()");
}

javax::crypto::SecretKey* javax::crypto::KeyGenerator::generateKey()
{ /* stub */
    unimplemented_(u"javax::crypto::SecretKey* javax::crypto::KeyGenerator::generateKey()");
    return 0;
}

java::lang::String* javax::crypto::KeyGenerator::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0)");
    return 0;
}

javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::crypto::KeyGenerator* javax::crypto::KeyGenerator::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

java::security::Provider* javax::crypto::KeyGenerator::getProvider()
{ /* stub */
return provider ; /* getter */
}

void javax::crypto::KeyGenerator::init_(::java::security::SecureRandom* arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::init_(::java::security::SecureRandom* arg0)");
}

void javax::crypto::KeyGenerator::init_(::java::security::spec::AlgorithmParameterSpec* arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::init_(::java::security::spec::AlgorithmParameterSpec* arg0)");
}

void javax::crypto::KeyGenerator::init_(int32_t arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::init_(int32_t arg0)");
}

void javax::crypto::KeyGenerator::init_(::java::security::spec::AlgorithmParameterSpec* arg0, ::java::security::SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::init_(::java::security::spec::AlgorithmParameterSpec* arg0, ::java::security::SecureRandom* arg1)");
}

void javax::crypto::KeyGenerator::init_(int32_t arg0, ::java::security::SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void javax::crypto::KeyGenerator::init_(int32_t arg0, ::java::security::SecureRandom* arg1)");
}

/* private: javax::crypto::KeyGeneratorSpi* javax::crypto::KeyGenerator::nextSpi(KeyGeneratorSpi* arg0, bool arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::crypto::KeyGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.crypto.KeyGenerator", 25);
    return c;
}

java::lang::Class* javax::crypto::KeyGenerator::getClass0()
{
    return class_();
}

