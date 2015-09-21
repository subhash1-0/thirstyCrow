// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyPairGenerator_Delegate.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyPairGenerator_Delegate::KeyPairGenerator_Delegate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyPairGenerator_Delegate::KeyPairGenerator_Delegate(KeyPairGeneratorSpi* arg0, ::java::lang::String* arg1)
    : KeyPairGenerator_Delegate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::security::KeyPairGenerator_Delegate::KeyPairGenerator_Delegate(::sun::security::jca::GetInstance_Instance* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)
    : KeyPairGenerator_Delegate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int32_t java::security::KeyPairGenerator_Delegate::I_NONE;
constexpr int32_t java::security::KeyPairGenerator_Delegate::I_PARAMS;
constexpr int32_t java::security::KeyPairGenerator_Delegate::I_SIZE;

void ::java::security::KeyPairGenerator_Delegate::ctor(KeyPairGeneratorSpi* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyPairGenerator_Delegate::ctor(KeyPairGeneratorSpi* arg0, ::java::lang::String* arg1)");
}

void ::java::security::KeyPairGenerator_Delegate::ctor(::sun::security::jca::GetInstance_Instance* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyPairGenerator_Delegate::ctor(::sun::security::jca::GetInstance_Instance* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)");
}

void java::security::KeyPairGenerator_Delegate::disableFailover()
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator_Delegate::disableFailover()");
}

java::security::KeyPair* java::security::KeyPairGenerator_Delegate::generateKeyPair()
{ /* stub */
    unimplemented_(u"java::security::KeyPair* java::security::KeyPairGenerator_Delegate::generateKeyPair()");
    return 0;
}

void java::security::KeyPairGenerator_Delegate::initialize(int32_t arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator_Delegate::initialize(int32_t arg0, SecureRandom* arg1)");
}

void java::security::KeyPairGenerator_Delegate::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyPairGenerator_Delegate::initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1)");
}

/* private: java::security::KeyPairGeneratorSpi* java::security::KeyPairGenerator_Delegate::nextSpi(KeyPairGeneratorSpi* arg0, bool arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyPairGenerator_Delegate::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyPairGenerator.Delegate", 39);
    return c;
}

void java::security::KeyPairGenerator_Delegate::initialize(int32_t arg0)
{
    super::initialize(arg0);
}

void java::security::KeyPairGenerator_Delegate::initialize(::java::security::spec::AlgorithmParameterSpec* arg0)
{
    super::initialize(arg0);
}

java::lang::Class* java::security::KeyPairGenerator_Delegate::getClass0()
{
    return class_();
}

