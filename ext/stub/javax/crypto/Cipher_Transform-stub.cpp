// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar
#include <javax/crypto/Cipher_Transform.hpp>

extern void unimplemented_(const char16_t* name);
javax::crypto::Cipher_Transform::Cipher_Transform(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::crypto::Cipher_Transform::Cipher_Transform(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3)
    : Cipher_Transform(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

java::util::concurrent::ConcurrentMap*& javax::crypto::Cipher_Transform::patternCache()
{
    clinit();
    return patternCache_;
}
java::util::concurrent::ConcurrentMap* javax::crypto::Cipher_Transform::patternCache_;

void ::javax::crypto::Cipher_Transform::ctor(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::Cipher_Transform::ctor(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3)");
}

/* private: bool javax::crypto::Cipher_Transform::matches(::java::lang::String* arg0, ::java::lang::String* arg1) */
void javax::crypto::Cipher_Transform::setModePadding(CipherSpi* arg0)
{ /* stub */
    unimplemented_(u"void javax::crypto::Cipher_Transform::setModePadding(CipherSpi* arg0)");
}

/* private: int32_t javax::crypto::Cipher_Transform::supports(::java::security::Provider_Service* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) */
int32_t javax::crypto::Cipher_Transform::supportsMode(::java::security::Provider_Service* arg0)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher_Transform::supportsMode(::java::security::Provider_Service* arg0)");
    return 0;
}

int32_t javax::crypto::Cipher_Transform::supportsModePadding(::java::security::Provider_Service* arg0)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher_Transform::supportsModePadding(::java::security::Provider_Service* arg0)");
    return 0;
}

int32_t javax::crypto::Cipher_Transform::supportsPadding(::java::security::Provider_Service* arg0)
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::Cipher_Transform::supportsPadding(::java::security::Provider_Service* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::crypto::Cipher_Transform::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.crypto.Cipher.Transform", 29);
    return c;
}

java::lang::Class* javax::crypto::Cipher_Transform::getClass0()
{
    return class_();
}

