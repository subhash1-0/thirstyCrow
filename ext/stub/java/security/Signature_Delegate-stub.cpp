// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Signature_Delegate.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Signature_Delegate::Signature_Delegate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Signature_Delegate::Signature_Delegate(SignatureSpi* arg0, ::java::lang::String* arg1)
    : Signature_Delegate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::security::Signature_Delegate::Signature_Delegate(Provider_Service* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)
    : Signature_Delegate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int32_t java::security::Signature_Delegate::I_PRIV;
constexpr int32_t java::security::Signature_Delegate::I_PRIV_SR;
constexpr int32_t java::security::Signature_Delegate::I_PUB;
int32_t& java::security::Signature_Delegate::warnCount()
{
    clinit();
    return warnCount_;
}
int32_t java::security::Signature_Delegate::warnCount_;

void ::java::security::Signature_Delegate::ctor(SignatureSpi* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Signature_Delegate::ctor(SignatureSpi* arg0, ::java::lang::String* arg1)");
}

void ::java::security::Signature_Delegate::ctor(Provider_Service* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Signature_Delegate::ctor(Provider_Service* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2)");
}

void java::security::Signature_Delegate::chooseFirstProvider()
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::chooseFirstProvider()");
}

/* private: void java::security::Signature_Delegate::chooseProvider(int32_t arg0, Key* arg1, SecureRandom* arg2) */
java::lang::Object* java::security::Signature_Delegate::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Signature_Delegate::clone()");
    return 0;
}

java::lang::Object* java::security::Signature_Delegate::engineGetParameter(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Signature_Delegate::engineGetParameter(::java::lang::String* arg0)");
    return 0;
}

java::security::AlgorithmParameters* java::security::Signature_Delegate::engineGetParameters()
{ /* stub */
    unimplemented_(u"java::security::AlgorithmParameters* java::security::Signature_Delegate::engineGetParameters()");
    return 0;
}

void java::security::Signature_Delegate::engineInitSign(PrivateKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineInitSign(PrivateKey* arg0)");
}

void java::security::Signature_Delegate::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineInitSign(PrivateKey* arg0, SecureRandom* arg1)");
}

void java::security::Signature_Delegate::engineInitVerify(PublicKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineInitVerify(PublicKey* arg0)");
}

void java::security::Signature_Delegate::engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0)");
}

void java::security::Signature_Delegate::engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)");
}

int8_tArray* java::security::Signature_Delegate::engineSign()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::Signature_Delegate::engineSign()");
    return 0;
}

int32_t java::security::Signature_Delegate::engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::security::Signature_Delegate::engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::security::Signature_Delegate::engineUpdate(int8_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineUpdate(int8_t arg0)");
}

void java::security::Signature_Delegate::engineUpdate(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineUpdate(::java::nio::ByteBuffer* arg0)");
}

void java::security::Signature_Delegate::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::security::Signature_Delegate::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

bool java::security::Signature_Delegate::engineVerify(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::Signature_Delegate::engineVerify(::int8_tArray* arg0)");
    return 0;
}

bool java::security::Signature_Delegate::engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"bool java::security::Signature_Delegate::engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

/* private: void java::security::Signature_Delegate::init_(SignatureSpi* arg0, int32_t arg1, Key* arg2, SecureRandom* arg3) */
/* private: java::security::SignatureSpi* java::security::Signature_Delegate::newInstance(Provider_Service* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Signature_Delegate::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Signature.Delegate", 32);
    return c;
}

java::lang::Class* java::security::Signature_Delegate::getClass0()
{
    return class_();
}

