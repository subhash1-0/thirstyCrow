// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_PrivateKeyEntry.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
} // java

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_PrivateKeyEntry::KeyStore_PrivateKeyEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_PrivateKeyEntry::KeyStore_PrivateKeyEntry(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1)
    : KeyStore_PrivateKeyEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::security::KeyStore_PrivateKeyEntry::KeyStore_PrivateKeyEntry(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1, ::java::util::Set* arg2)
    : KeyStore_PrivateKeyEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::security::KeyStore_PrivateKeyEntry::ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_PrivateKeyEntry::ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1)");
}

void ::java::security::KeyStore_PrivateKeyEntry::ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1, ::java::util::Set* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_PrivateKeyEntry::ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1, ::java::util::Set* arg2)");
}

java::util::Set* java::security::KeyStore_PrivateKeyEntry::getAttributes()
{ /* stub */
return attributes ; /* getter */
}

java::security::cert::Certificate* java::security::KeyStore_PrivateKeyEntry::getCertificate()
{ /* stub */
    unimplemented_(u"java::security::cert::Certificate* java::security::KeyStore_PrivateKeyEntry::getCertificate()");
    return 0;
}

java::security::cert::CertificateArray* java::security::KeyStore_PrivateKeyEntry::getCertificateChain()
{ /* stub */
    unimplemented_(u"java::security::cert::CertificateArray* java::security::KeyStore_PrivateKeyEntry::getCertificateChain()");
    return 0;
}

java::security::PrivateKey* java::security::KeyStore_PrivateKeyEntry::getPrivateKey()
{ /* stub */
    unimplemented_(u"java::security::PrivateKey* java::security::KeyStore_PrivateKeyEntry::getPrivateKey()");
    return 0;
}

java::lang::String* java::security::KeyStore_PrivateKeyEntry::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::KeyStore_PrivateKeyEntry::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_PrivateKeyEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.PrivateKeyEntry", 38);
    return c;
}

java::lang::Class* java::security::KeyStore_PrivateKeyEntry::getClass0()
{
    return class_();
}

