// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/spec/RSAPrivateKeySpec.hpp>

extern void unimplemented_(const char16_t* name);
java::security::spec::RSAPrivateKeySpec::RSAPrivateKeySpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::spec::RSAPrivateKeySpec::RSAPrivateKeySpec(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)
    : RSAPrivateKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::security::spec::RSAPrivateKeySpec::ctor(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::spec::RSAPrivateKeySpec::ctor(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)");
}

java::math::BigInteger* java::security::spec::RSAPrivateKeySpec::getModulus()
{ /* stub */
return modulus ; /* getter */
}

java::math::BigInteger* java::security::spec::RSAPrivateKeySpec::getPrivateExponent()
{ /* stub */
return privateExponent ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::spec::RSAPrivateKeySpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.spec.RSAPrivateKeySpec", 36);
    return c;
}

java::lang::Class* java::security::spec::RSAPrivateKeySpec::getClass0()
{
    return class_();
}

