// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/spec/RSAKeyGenParameterSpec.hpp>

extern void unimplemented_(const char16_t* name);
java::security::spec::RSAKeyGenParameterSpec::RSAKeyGenParameterSpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::spec::RSAKeyGenParameterSpec::RSAKeyGenParameterSpec(int32_t arg0, ::java::math::BigInteger* arg1)
    : RSAKeyGenParameterSpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::math::BigInteger*& java::security::spec::RSAKeyGenParameterSpec::F0()
{
    clinit();
    return F0_;
}
java::math::BigInteger* java::security::spec::RSAKeyGenParameterSpec::F0_;
java::math::BigInteger*& java::security::spec::RSAKeyGenParameterSpec::F4()
{
    clinit();
    return F4_;
}
java::math::BigInteger* java::security::spec::RSAKeyGenParameterSpec::F4_;

void ::java::security::spec::RSAKeyGenParameterSpec::ctor(int32_t arg0, ::java::math::BigInteger* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::spec::RSAKeyGenParameterSpec::ctor(int32_t arg0, ::java::math::BigInteger* arg1)");
}

int32_t java::security::spec::RSAKeyGenParameterSpec::getKeysize()
{ /* stub */
return keysize ; /* getter */
}

java::math::BigInteger* java::security::spec::RSAKeyGenParameterSpec::getPublicExponent()
{ /* stub */
return publicExponent ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::spec::RSAKeyGenParameterSpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.spec.RSAKeyGenParameterSpec", 41);
    return c;
}

java::lang::Class* java::security::spec::RSAKeyGenParameterSpec::getClass0()
{
    return class_();
}

