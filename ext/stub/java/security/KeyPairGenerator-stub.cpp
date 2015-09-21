// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyPairGenerator.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyPairGenerator::KeyPairGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyPairGenerator::KeyPairGenerator(::java::lang::String* arg0)
    : KeyPairGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

sun::security::util::Debug*& java::security::KeyPairGenerator::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* java::security::KeyPairGenerator::pdebug_;
bool& java::security::KeyPairGenerator::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool java::security::KeyPairGenerator::skipDebug_;

void ::java::security::KeyPairGenerator::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyPairGenerator::ctor(::java::lang::String* arg0)");
}

void java::security::KeyPairGenerator::disableFailover()
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator::disableFailover()");
}

java::security::KeyPair* java::security::KeyPairGenerator::genKeyPair()
{ /* stub */
    unimplemented_(u"java::security::KeyPair* java::security::KeyPairGenerator::genKeyPair()");
    return 0;
}

java::security::KeyPair* java::security::KeyPairGenerator::generateKeyPair()
{ /* stub */
    unimplemented_(u"java::security::KeyPair* java::security::KeyPairGenerator::generateKeyPair()");
    return 0;
}

java::lang::String* java::security::KeyPairGenerator::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0)");
    return 0;
}

/* private: java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::sun::security::jca::GetInstance_Instance* arg0, ::java::lang::String* arg1) */
java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyPairGenerator* java::security::KeyPairGenerator::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

java::security::Provider* java::security::KeyPairGenerator::getProvider()
{ /* stub */
return provider ; /* getter */
}

void java::security::KeyPairGenerator::initialize(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator::initialize(int32_t arg0)");
}

void java::security::KeyPairGenerator::initialize(::java::security::spec::AlgorithmParameterSpec* arg0)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator::initialize(::java::security::spec::AlgorithmParameterSpec* arg0)");
}

void java::security::KeyPairGenerator::initialize(int32_t arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator::initialize(int32_t arg0, SecureRandom* arg1)");
}

void java::security::KeyPairGenerator::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyPairGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyPairGenerator", 30);
    return c;
}

java::lang::Class* java::security::KeyPairGenerator::getClass0()
{
    return class_();
}

