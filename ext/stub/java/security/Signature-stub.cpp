// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Signature.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Signature::Signature(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Signature::Signature(::java::lang::String* arg0)
    : Signature(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::String*& java::security::Signature::RSA_CIPHER()
{
    clinit();
    return RSA_CIPHER_;
}
java::lang::String* java::security::Signature::RSA_CIPHER_;
java::lang::String*& java::security::Signature::RSA_SIGNATURE()
{
    clinit();
    return RSA_SIGNATURE_;
}
java::lang::String* java::security::Signature::RSA_SIGNATURE_;
constexpr int32_t java::security::Signature::SIGN;
constexpr int32_t java::security::Signature::UNINITIALIZED;
constexpr int32_t java::security::Signature::VERIFY;
sun::security::util::Debug*& java::security::Signature::debug()
{
    clinit();
    return debug_;
}
sun::security::util::Debug* java::security::Signature::debug_;
sun::security::util::Debug*& java::security::Signature::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* java::security::Signature::pdebug_;
java::util::List*& java::security::Signature::rsaIds()
{
    clinit();
    return rsaIds_;
}
java::util::List* java::security::Signature::rsaIds_;
java::util::Map*& java::security::Signature::signatureInfo()
{
    clinit();
    return signatureInfo_;
}
java::util::Map* java::security::Signature::signatureInfo_;
bool& java::security::Signature::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool java::security::Signature::skipDebug_;

void ::java::security::Signature::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Signature::ctor(::java::lang::String* arg0)");
}

void java::security::Signature::chooseFirstProvider()
{ /* stub */
    unimplemented_(u"void java::security::Signature::chooseFirstProvider()");
}

java::lang::Object* java::security::Signature::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Signature::clone()");
    return 0;
}

java::lang::String* java::security::Signature::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0)");
    return 0;
}

/* private: java::security::Signature* java::security::Signature::getInstance(::sun::security::jca::GetInstance_Instance* arg0, ::java::lang::String* arg1) */
java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::Signature* java::security::Signature::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

/* private: java::security::Signature* java::security::Signature::getInstanceRSA(Provider* arg0) */
java::lang::Object* java::security::Signature::getParameter(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Signature::getParameter(::java::lang::String* arg0)");
    return 0;
}

java::security::AlgorithmParameters* java::security::Signature::getParameters()
{ /* stub */
    unimplemented_(u"java::security::AlgorithmParameters* java::security::Signature::getParameters()");
    return 0;
}

java::security::Provider* java::security::Signature::getProvider()
{ /* stub */
return provider ; /* getter */
}

void java::security::Signature::initSign(PrivateKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::initSign(PrivateKey* arg0)");
}

void java::security::Signature::initSign(PrivateKey* arg0, SecureRandom* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature::initSign(PrivateKey* arg0, SecureRandom* arg1)");
}

void java::security::Signature::initVerify(PublicKey* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::initVerify(PublicKey* arg0)");
}

void java::security::Signature::initVerify(::java::security::cert::Certificate* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::initVerify(::java::security::cert::Certificate* arg0)");
}

/* private: bool java::security::Signature::isSpi(Provider_Service* arg0) */
void java::security::Signature::setParameter(::java::security::spec::AlgorithmParameterSpec* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::setParameter(::java::security::spec::AlgorithmParameterSpec* arg0)");
}

void java::security::Signature::setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Signature::setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)");
}

int8_tArray* java::security::Signature::sign()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::Signature::sign()");
    return 0;
}

int32_t java::security::Signature::sign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::security::Signature::sign(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

java::lang::String* java::security::Signature::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::Signature::toString()");
    return 0;
}

void java::security::Signature::update(int8_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::update(int8_t arg0)");
}

void java::security::Signature::update(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::update(::int8_tArray* arg0)");
}

void java::security::Signature::update(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void java::security::Signature::update(::java::nio::ByteBuffer* arg0)");
}

void java::security::Signature::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::security::Signature::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

bool java::security::Signature::verify(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::Signature::verify(::int8_tArray* arg0)");
    return 0;
}

bool java::security::Signature::verify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"bool java::security::Signature::verify(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Signature::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Signature", 23);
    return c;
}

java::lang::Class* java::security::Signature::getClass0()
{
    return class_();
}

