// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar
#include <javax/crypto/spec/IvParameterSpec.hpp>

extern void unimplemented_(const char16_t* name);
javax::crypto::spec::IvParameterSpec::IvParameterSpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::crypto::spec::IvParameterSpec::IvParameterSpec(::int8_tArray* arg0)
    : IvParameterSpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

javax::crypto::spec::IvParameterSpec::IvParameterSpec(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
    : IvParameterSpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::javax::crypto::spec::IvParameterSpec::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::spec::IvParameterSpec::ctor(::int8_tArray* arg0)");
}

void ::javax::crypto::spec::IvParameterSpec::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::spec::IvParameterSpec::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

int8_tArray* javax::crypto::spec::IvParameterSpec::getIV()
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::spec::IvParameterSpec::getIV()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::crypto::spec::IvParameterSpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.crypto.spec.IvParameterSpec", 33);
    return c;
}

java::lang::Class* javax::crypto::spec::IvParameterSpec::getClass0()
{
    return class_();
}

