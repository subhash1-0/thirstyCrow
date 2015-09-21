// Generated from /pastry-2.1/lib/bouncycastle.jar
#include <org/bouncycastle/jce/provider/BouncyCastleProvider.hpp>

extern void unimplemented_(const char16_t* name);
org::bouncycastle::jce::provider::BouncyCastleProvider::BouncyCastleProvider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::bouncycastle::jce::provider::BouncyCastleProvider::BouncyCastleProvider()
    : BouncyCastleProvider(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::String*& org::bouncycastle::jce::provider::BouncyCastleProvider::PROVIDER_NAME()
{
    clinit();
    return PROVIDER_NAME_;
}
java::lang::String* org::bouncycastle::jce::provider::BouncyCastleProvider::PROVIDER_NAME_;
java::lang::StringArray*& org::bouncycastle::jce::provider::BouncyCastleProvider::SYMMETRIC_CIPHERS()
{
    clinit();
    return SYMMETRIC_CIPHERS_;
}
java::lang::StringArray* org::bouncycastle::jce::provider::BouncyCastleProvider::SYMMETRIC_CIPHERS_;
java::lang::String*& org::bouncycastle::jce::provider::BouncyCastleProvider::SYMMETRIC_CIPHER_PACKAGE()
{
    clinit();
    return SYMMETRIC_CIPHER_PACKAGE_;
}
java::lang::String* org::bouncycastle::jce::provider::BouncyCastleProvider::SYMMETRIC_CIPHER_PACKAGE_;
java::lang::String*& org::bouncycastle::jce::provider::BouncyCastleProvider::info()
{
    clinit();
    return info_;
}
java::lang::String* org::bouncycastle::jce::provider::BouncyCastleProvider::info_;

void ::org::bouncycastle::jce::provider::BouncyCastleProvider::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::bouncycastle::jce::provider::BouncyCastleProvider::ctor()");
}

/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addHMACAlgorithm(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addHMACAlias(::java::lang::String* arg0, ::org::bouncycastle::asn1::DERObjectIdentifier* arg1) */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addMacAlgorithms() */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addMappings(::java::util::Map* arg0) */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addMessageDigestAlgorithms() */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addSignatureAlgorithm(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::org::bouncycastle::asn1::DERObjectIdentifier* arg3) */
/* private: void org::bouncycastle::jce::provider::BouncyCastleProvider::addSignatureAlgorithms() */
void org::bouncycastle::jce::provider::BouncyCastleProvider::setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void org::bouncycastle::jce::provider::BouncyCastleProvider::setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::bouncycastle::jce::provider::BouncyCastleProvider::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.bouncycastle.jce.provider.BouncyCastleProvider", 50);
    return c;
}

java::lang::Class* org::bouncycastle::jce::provider::BouncyCastleProvider::getClass0()
{
    return class_();
}

