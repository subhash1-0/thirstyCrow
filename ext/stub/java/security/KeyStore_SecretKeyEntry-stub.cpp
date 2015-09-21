// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_SecretKeyEntry.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_SecretKeyEntry::KeyStore_SecretKeyEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_SecretKeyEntry::KeyStore_SecretKeyEntry(::javax::crypto::SecretKey* arg0)
    : KeyStore_SecretKeyEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::security::KeyStore_SecretKeyEntry::KeyStore_SecretKeyEntry(::javax::crypto::SecretKey* arg0, ::java::util::Set* arg1)
    : KeyStore_SecretKeyEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::security::KeyStore_SecretKeyEntry::ctor(::javax::crypto::SecretKey* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_SecretKeyEntry::ctor(::javax::crypto::SecretKey* arg0)");
}

void ::java::security::KeyStore_SecretKeyEntry::ctor(::javax::crypto::SecretKey* arg0, ::java::util::Set* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_SecretKeyEntry::ctor(::javax::crypto::SecretKey* arg0, ::java::util::Set* arg1)");
}

java::util::Set* java::security::KeyStore_SecretKeyEntry::getAttributes()
{ /* stub */
return attributes ; /* getter */
}

javax::crypto::SecretKey* java::security::KeyStore_SecretKeyEntry::getSecretKey()
{ /* stub */
    unimplemented_(u"javax::crypto::SecretKey* java::security::KeyStore_SecretKeyEntry::getSecretKey()");
    return 0;
}

java::lang::String* java::security::KeyStore_SecretKeyEntry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::KeyStore_SecretKeyEntry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_SecretKeyEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.SecretKeyEntry", 37);
    return c;
}

java::lang::Class* java::security::KeyStore_SecretKeyEntry::getClass0()
{
    return class_();
}

