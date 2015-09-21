// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_CallbackHandlerProtection.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_CallbackHandlerProtection::KeyStore_CallbackHandlerProtection(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_CallbackHandlerProtection::KeyStore_CallbackHandlerProtection(::javax::security::auth::callback::CallbackHandler* arg0)
    : KeyStore_CallbackHandlerProtection(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::KeyStore_CallbackHandlerProtection::ctor(::javax::security::auth::callback::CallbackHandler* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_CallbackHandlerProtection::ctor(::javax::security::auth::callback::CallbackHandler* arg0)");
}

javax::security::auth::callback::CallbackHandler* java::security::KeyStore_CallbackHandlerProtection::getCallbackHandler()
{ /* stub */
    unimplemented_(u"javax::security::auth::callback::CallbackHandler* java::security::KeyStore_CallbackHandlerProtection::getCallbackHandler()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_CallbackHandlerProtection::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.CallbackHandlerProtection", 48);
    return c;
}

java::lang::Class* java::security::KeyStore_CallbackHandlerProtection::getClass0()
{
    return class_();
}

