// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/spec/EncodedKeySpec.hpp>

extern void unimplemented_(const char16_t* name);
java::security::spec::EncodedKeySpec::EncodedKeySpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::spec::EncodedKeySpec::EncodedKeySpec(::int8_tArray* arg0)
    : EncodedKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::spec::EncodedKeySpec::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::spec::EncodedKeySpec::ctor(::int8_tArray* arg0)");
}

int8_tArray* java::security::spec::EncodedKeySpec::getEncoded()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::spec::EncodedKeySpec::getEncoded()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::spec::EncodedKeySpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.spec.EncodedKeySpec", 33);
    return c;
}

java::lang::Class* java::security::spec::EncodedKeySpec::getClass0()
{
    return class_();
}

