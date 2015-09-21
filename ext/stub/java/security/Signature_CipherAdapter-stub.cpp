// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Signature_CipherAdapter.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Signature_CipherAdapter::Signature_CipherAdapter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Signature_CipherAdapter::Signature_CipherAdapter(::javax::crypto::Cipher* arg0)
    : Signature_CipherAdapter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::Signature_CipherAdapter::ctor(::javax::crypto::Cipher* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Signature_CipherAdapter::ctor(::javax::crypto::Cipher* arg0)");
}

java::lang::Object* java::security::Signature_CipherAdapter::engineGetParameter(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Signature_CipherAdapter::engineGetParameter(::java::lang::String* arg0)");
    return 0;
}

void java::security::Signature_CipherAdapter::engineInitSign(PrivateKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineInitSign(PrivateKey* arg0)");
}

void java::security::Signature_CipherAdapter::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)");
}

void java::security::Signature_CipherAdapter::engineInitVerify(PublicKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineInitVerify(PublicKey* arg0)");
}

void java::security::Signature_CipherAdapter::engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)");
}

int8_tArray* java::security::Signature_CipherAdapter::engineSign()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::Signature_CipherAdapter::engineSign()");
    return 0;
}

void java::security::Signature_CipherAdapter::engineUpdate(int8_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineUpdate(int8_t arg0)");
}

void java::security::Signature_CipherAdapter::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::security::Signature_CipherAdapter::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

bool java::security::Signature_CipherAdapter::engineVerify(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::Signature_CipherAdapter::engineVerify(::int8_tArray* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Signature_CipherAdapter::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Signature.CipherAdapter", 37);
    return c;
}

void java::security::Signature_CipherAdapter::engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0)
{
    super::engineSetParameter(arg0);
}

int32_t java::security::Signature_CipherAdapter::engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{
    return super::engineSign(arg0, arg1, arg2);
}

void java::security::Signature_CipherAdapter::engineUpdate(::java::nio::ByteBuffer* arg0)
{
    super::engineUpdate(arg0);
}

bool java::security::Signature_CipherAdapter::engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{
    return super::engineVerify(arg0, arg1, arg2);
}

java::lang::Class* java::security::Signature_CipherAdapter::getClass0()
{
    return class_();
}

