// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/cert/X509Certificate.hpp>

extern void unimplemented_(const char16_t* name);
java::security::cert::X509Certificate::X509Certificate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::cert::X509Certificate::X509Certificate()
    : X509Certificate(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int64_t java::security::cert::X509Certificate::serialVersionUID;

void ::java::security::cert::X509Certificate::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::cert::X509Certificate::ctor()");
}

java::util::List* java::security::cert::X509Certificate::getExtendedKeyUsage()
{ /* stub */
    unimplemented_(u"java::util::List* java::security::cert::X509Certificate::getExtendedKeyUsage()");
    return 0;
}

java::util::Collection* java::security::cert::X509Certificate::getIssuerAlternativeNames()
{ /* stub */
    unimplemented_(u"java::util::Collection* java::security::cert::X509Certificate::getIssuerAlternativeNames()");
    return 0;
}

javax::security::auth::x500::X500Principal* java::security::cert::X509Certificate::getIssuerX500Principal()
{ /* stub */
return issuerX500Principal ; /* getter */
}

java::util::Collection* java::security::cert::X509Certificate::getSubjectAlternativeNames()
{ /* stub */
    unimplemented_(u"java::util::Collection* java::security::cert::X509Certificate::getSubjectAlternativeNames()");
    return 0;
}

javax::security::auth::x500::X500Principal* java::security::cert::X509Certificate::getSubjectX500Principal()
{ /* stub */
return subjectX500Principal ; /* getter */
}

void java::security::cert::X509Certificate::verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1)
{ /* stub */
    unimplemented_(u"void java::security::cert::X509Certificate::verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::cert::X509Certificate::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.cert.X509Certificate", 34);
    return c;
}

java::lang::Class* java::security::cert::X509Certificate::getClass0()
{
    return class_();
}

