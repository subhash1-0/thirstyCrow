// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/cert/Certificate_CertificateRep.hpp>

extern void unimplemented_(const char16_t* name);
java::security::cert::Certificate_CertificateRep::Certificate_CertificateRep(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::cert::Certificate_CertificateRep::Certificate_CertificateRep(::java::lang::String* arg0, ::int8_tArray* arg1)
    : Certificate_CertificateRep(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::security::cert::Certificate_CertificateRep::serialVersionUID;

void ::java::security::cert::Certificate_CertificateRep::ctor(::java::lang::String* arg0, ::int8_tArray* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::cert::Certificate_CertificateRep::ctor(::java::lang::String* arg0, ::int8_tArray* arg1)");
}

java::lang::Object* java::security::cert::Certificate_CertificateRep::readResolve()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::cert::Certificate_CertificateRep::readResolve()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::cert::Certificate_CertificateRep::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.cert.Certificate.CertificateRep", 45);
    return c;
}

java::lang::Class* java::security::cert::Certificate_CertificateRep::getClass0()
{
    return class_();
}

