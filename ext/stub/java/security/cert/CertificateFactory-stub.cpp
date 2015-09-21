// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/cert/CertificateFactory.hpp>

extern void unimplemented_(const char16_t* name);
java::security::cert::CertificateFactory::CertificateFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::cert::CertificateFactory::CertificateFactory(CertificateFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : CertificateFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::security::cert::CertificateFactory::ctor(CertificateFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::cert::CertificateFactory::ctor(CertificateFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

java::security::cert::CRL* java::security::cert::CertificateFactory::generateCRL(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::CRL* java::security::cert::CertificateFactory::generateCRL(::java::io::InputStream* arg0)");
    return 0;
}

java::util::Collection* java::security::cert::CertificateFactory::generateCRLs(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::util::Collection* java::security::cert::CertificateFactory::generateCRLs(::java::io::InputStream* arg0)");
    return 0;
}

java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::io::InputStream* arg0)");
    return 0;
}

java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::util::List* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::util::List* arg0)");
    return 0;
}

java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::io::InputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"java::security::cert::CertPath* java::security::cert::CertificateFactory::generateCertPath(::java::io::InputStream* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::cert::Certificate* java::security::cert::CertificateFactory::generateCertificate(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::Certificate* java::security::cert::CertificateFactory::generateCertificate(::java::io::InputStream* arg0)");
    return 0;
}

java::util::Collection* java::security::cert::CertificateFactory::generateCertificates(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"java::util::Collection* java::security::cert::CertificateFactory::generateCertificates(::java::io::InputStream* arg0)");
    return 0;
}

java::util::Iterator* java::security::cert::CertificateFactory::getCertPathEncodings()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::security::cert::CertificateFactory::getCertPathEncodings()");
    return 0;
}

java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0)");
    return 0;
}

java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::cert::CertificateFactory* java::security::cert::CertificateFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

java::security::Provider* java::security::cert::CertificateFactory::getProvider()
{ /* stub */
return provider ; /* getter */
}

java::lang::String* java::security::cert::CertificateFactory::getType()
{ /* stub */
return type ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::cert::CertificateFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.cert.CertificateFactory", 37);
    return c;
}

java::lang::Class* java::security::cert::CertificateFactory::getClass0()
{
    return class_();
}

