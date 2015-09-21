// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/SecureRandom.hpp>

extern void unimplemented_(const char16_t* name);
java::security::SecureRandom::SecureRandom(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::SecureRandom::SecureRandom()
    : SecureRandom(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::security::SecureRandom::SecureRandom(::int8_tArray* arg0)
    : SecureRandom(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::security::SecureRandom::SecureRandom(SecureRandomSpi* arg0, Provider* arg1)
    : SecureRandom(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

sun::security::util::Debug*& java::security::SecureRandom::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* java::security::SecureRandom::pdebug_;
std::atomic< java::security::SecureRandom* >& java::security::SecureRandom::seedGenerator()
{
    clinit();
    return seedGenerator_;
}
std::atomic< java::security::SecureRandom* > java::security::SecureRandom::seedGenerator_;
constexpr int64_t java::security::SecureRandom::serialVersionUID;
bool& java::security::SecureRandom::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool java::security::SecureRandom::skipDebug_;

void ::java::security::SecureRandom::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::SecureRandom::ctor()");
}

void ::java::security::SecureRandom::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::SecureRandom::ctor(::int8_tArray* arg0)");
}

void ::java::security::SecureRandom::ctor(SecureRandomSpi* arg0, Provider* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::SecureRandom::ctor(SecureRandomSpi* arg0, Provider* arg1)");
}

/* private: void ::java::security::SecureRandom::ctor(SecureRandomSpi* arg0, Provider* arg1, ::java::lang::String* arg2) */
int8_tArray* java::security::SecureRandom::generateSeed(int32_t arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::SecureRandom::generateSeed(int32_t arg0)");
    return 0;
}

java::lang::String* java::security::SecureRandom::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

/* private: void java::security::SecureRandom::getDefaultPRNG(bool arg0, ::int8_tArray* arg1) */
java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0)");
    return 0;
}

java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::SecureRandom* java::security::SecureRandom::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

java::security::SecureRandom* java::security::SecureRandom::getInstanceStrong()
{ /* stub */
    clinit();
    unimplemented_(u"java::security::SecureRandom* java::security::SecureRandom::getInstanceStrong()");
    return 0;
}

/* private: java::lang::String* java::security::SecureRandom::getPrngAlgorithm() */
java::security::Provider* java::security::SecureRandom::getProvider()
{ /* stub */
return provider ; /* getter */
}

java::security::SecureRandomSpi* java::security::SecureRandom::getSecureRandomSpi()
{ /* stub */
return secureRandomSpi ; /* getter */
}

int8_tArray* java::security::SecureRandom::getSeed(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int8_tArray* java::security::SecureRandom::getSeed(int32_t arg0)");
    return 0;
}

/* private: int8_tArray* java::security::SecureRandom::longToByteArray_(int64_t arg0) */
int32_t java::security::SecureRandom::next(int32_t arg0)
{ /* stub */
    unimplemented_(u"int32_t java::security::SecureRandom::next(int32_t arg0)");
    return 0;
}

void java::security::SecureRandom::nextBytes(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::security::SecureRandom::nextBytes(::int8_tArray* arg0)");
}

void java::security::SecureRandom::setSeed(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::security::SecureRandom::setSeed(::int8_tArray* arg0)");
}

void java::security::SecureRandom::setSeed(int64_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::SecureRandom::setSeed(int64_t arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::SecureRandom::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.SecureRandom", 26);
    return c;
}

java::lang::Class* java::security::SecureRandom::getClass0()
{
    return class_();
}

