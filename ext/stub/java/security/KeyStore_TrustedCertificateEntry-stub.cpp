// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_TrustedCertificateEntry.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_TrustedCertificateEntry::KeyStore_TrustedCertificateEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_TrustedCertificateEntry::KeyStore_TrustedCertificateEntry(::java::security::cert::Certificate* arg0)
    : KeyStore_TrustedCertificateEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::security::KeyStore_TrustedCertificateEntry::KeyStore_TrustedCertificateEntry(::java::security::cert::Certificate* arg0, ::java::util::Set* arg1)
    : KeyStore_TrustedCertificateEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::security::KeyStore_TrustedCertificateEntry::ctor(::java::security::cert::Certificate* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_TrustedCertificateEntry::ctor(::java::security::cert::Certificate* arg0)");
}

void ::java::security::KeyStore_TrustedCertificateEntry::ctor(::java::security::cert::Certificate* arg0, ::java::util::Set* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_TrustedCertificateEntry::ctor(::java::security::cert::Certificate* arg0, ::java::util::Set* arg1)");
}

java::util::Set* java::security::KeyStore_TrustedCertificateEntry::getAttributes()
{ /* stub */
return attributes ; /* getter */
}

java::security::cert::Certificate* java::security::KeyStore_TrustedCertificateEntry::getTrustedCertificate()
{ /* stub */
    unimplemented_(u"java::security::cert::Certificate* java::security::KeyStore_TrustedCertificateEntry::getTrustedCertificate()");
    return 0;
}

java::lang::String* java::security::KeyStore_TrustedCertificateEntry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::KeyStore_TrustedCertificateEntry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_TrustedCertificateEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.TrustedCertificateEntry", 46);
    return c;
}

java::lang::Class* java::security::KeyStore_TrustedCertificateEntry::getClass0()
{
    return class_();
}

