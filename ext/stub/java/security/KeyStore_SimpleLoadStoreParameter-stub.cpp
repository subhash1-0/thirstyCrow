// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_SimpleLoadStoreParameter.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_SimpleLoadStoreParameter::KeyStore_SimpleLoadStoreParameter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_SimpleLoadStoreParameter::KeyStore_SimpleLoadStoreParameter(KeyStore_ProtectionParameter* arg0)
    : KeyStore_SimpleLoadStoreParameter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::KeyStore_SimpleLoadStoreParameter::ctor(KeyStore_ProtectionParameter* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_SimpleLoadStoreParameter::ctor(KeyStore_ProtectionParameter* arg0)");
}

java::security::KeyStore_ProtectionParameter* java::security::KeyStore_SimpleLoadStoreParameter::getProtectionParameter()
{ /* stub */
    unimplemented_(u"java::security::KeyStore_ProtectionParameter* java::security::KeyStore_SimpleLoadStoreParameter::getProtectionParameter()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_SimpleLoadStoreParameter::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.SimpleLoadStoreParameter", 47);
    return c;
}

java::lang::Class* java::security::KeyStore_SimpleLoadStoreParameter::getClass0()
{
    return class_();
}

