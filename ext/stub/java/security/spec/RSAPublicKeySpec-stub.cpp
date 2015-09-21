// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/spec/RSAPublicKeySpec.hpp>

extern void unimplemented_(const char16_t* name);
java::security::spec::RSAPublicKeySpec::RSAPublicKeySpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::spec::RSAPublicKeySpec::RSAPublicKeySpec(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)
    : RSAPublicKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::security::spec::RSAPublicKeySpec::ctor(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::spec::RSAPublicKeySpec::ctor(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1)");
}

java::math::BigInteger* java::security::spec::RSAPublicKeySpec::getModulus()
{ /* stub */
return modulus ; /* getter */
}

java::math::BigInteger* java::security::spec::RSAPublicKeySpec::getPublicExponent()
{ /* stub */
return publicExponent ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::spec::RSAPublicKeySpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.spec.RSAPublicKeySpec", 35);
    return c;
}

java::lang::Class* java::security::spec::RSAPublicKeySpec::getClass0()
{
    return class_();
}

