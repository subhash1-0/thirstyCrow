// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/SignatureSpi.hpp>

extern void unimplemented_(const char16_t* name);
java::security::SignatureSpi::SignatureSpi(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::SignatureSpi::SignatureSpi()
    : SignatureSpi(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::security::SignatureSpi::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::SignatureSpi::ctor()");
}

java::lang::Object* java::security::SignatureSpi::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::SignatureSpi::clone()");
    return 0;
}

java::security::AlgorithmParameters* java::security::SignatureSpi::engineGetParameters()
{ /* stub */
    unimplemented_(u"java::security::AlgorithmParameters* java::security::SignatureSpi::engineGetParameters()");
    return 0;
}

void java::security::SignatureSpi::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::SignatureSpi::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)");
}

void java::security::SignatureSpi::engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0)
{ /* stub */
    unimplemented_(u"void java::security::SignatureSpi::engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0)");
}

int32_t java::security::SignatureSpi::engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::security::SignatureSpi::engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::security::SignatureSpi::engineUpdate(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void java::security::SignatureSpi::engineUpdate(::java::nio::ByteBuffer* arg0)");
}

bool java::security::SignatureSpi::engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"bool java::security::SignatureSpi::engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::SignatureSpi::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.SignatureSpi", 26);
    return c;
}

java::lang::Class* java::security::SignatureSpi::getClass0()
{
    return class_();
}

