// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyPairGeneratorSpi.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyPairGeneratorSpi::KeyPairGeneratorSpi(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyPairGeneratorSpi::KeyPairGeneratorSpi()
    : KeyPairGeneratorSpi(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::security::KeyPairGeneratorSpi::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyPairGeneratorSpi::ctor()");
}

void java::security::KeyPairGeneratorSpi::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGeneratorSpi::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyPairGeneratorSpi::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyPairGeneratorSpi", 33);
    return c;
}

java::lang::Class* java::security::KeyPairGeneratorSpi::getClass0()
{
    return class_();
}

