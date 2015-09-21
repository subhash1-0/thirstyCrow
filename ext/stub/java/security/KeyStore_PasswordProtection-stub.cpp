// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_PasswordProtection.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_PasswordProtection::KeyStore_PasswordProtection(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_PasswordProtection::KeyStore_PasswordProtection(::char16_tArray* arg0)
    : KeyStore_PasswordProtection(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::security::KeyStore_PasswordProtection::KeyStore_PasswordProtection(::char16_tArray* arg0, ::java::lang::String* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2)
    : KeyStore_PasswordProtection(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::security::KeyStore_PasswordProtection::ctor(::char16_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_PasswordProtection::ctor(::char16_tArray* arg0)");
}

void ::java::security::KeyStore_PasswordProtection::ctor(::char16_tArray* arg0, ::java::lang::String* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_PasswordProtection::ctor(::char16_tArray* arg0, ::java::lang::String* arg1, ::java::security::spec::AlgorithmParameterSpec* arg2)");
}

void java::security::KeyStore_PasswordProtection::destroy()
{ /* stub */
    unimplemented_(u"void java::security::KeyStore_PasswordProtection::destroy()");
}

char16_tArray* java::security::KeyStore_PasswordProtection::getPassword()
{ /* stub */
return password ; /* getter */
}

java::lang::String* java::security::KeyStore_PasswordProtection::getProtectionAlgorithm()
{ /* stub */
return protectionAlgorithm ; /* getter */
}

java::security::spec::AlgorithmParameterSpec* java::security::KeyStore_PasswordProtection::getProtectionParameters()
{ /* stub */
return protectionParameters ; /* getter */
}

bool java::security::KeyStore_PasswordProtection::isDestroyed()
{ /* stub */
    unimplemented_(u"bool java::security::KeyStore_PasswordProtection::isDestroyed()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_PasswordProtection::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.PasswordProtection", 41);
    return c;
}

java::lang::Class* java::security::KeyStore_PasswordProtection::getClass0()
{
    return class_();
}

