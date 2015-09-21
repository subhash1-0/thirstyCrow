// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/spec/X509EncodedKeySpec.hpp>

extern void unimplemented_(const char16_t* name);
java::security::spec::X509EncodedKeySpec::X509EncodedKeySpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::spec::X509EncodedKeySpec::X509EncodedKeySpec(::int8_tArray* arg0)
    : X509EncodedKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::spec::X509EncodedKeySpec::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::spec::X509EncodedKeySpec::ctor(::int8_tArray* arg0)");
}

int8_tArray* java::security::spec::X509EncodedKeySpec::getEncoded()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::spec::X509EncodedKeySpec::getEncoded()");
    return 0;
}

java::lang::String* java::security::spec::X509EncodedKeySpec::getFormat()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::spec::X509EncodedKeySpec::getFormat()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::spec::X509EncodedKeySpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.spec.X509EncodedKeySpec", 37);
    return c;
}

java::lang::Class* java::security::spec::X509EncodedKeySpec::getClass0()
{
    return class_();
}

