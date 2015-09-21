// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore.hpp>

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
java::security::KeyStore::KeyStore(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore::KeyStore(KeyStoreSpi* arg0, Provider* arg1, ::java::lang::String* arg2)
    : KeyStore(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::lang::String*& java::security::KeyStore::KEYSTORE_TYPE()
{
    clinit();
    return KEYSTORE_TYPE_;
}
java::lang::String* java::security::KeyStore::KEYSTORE_TYPE_;
sun::security::util::Debug*& java::security::KeyStore::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* java::security::KeyStore::pdebug_;
bool& java::security::KeyStore::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool java::security::KeyStore::skipDebug_;

void ::java::security::KeyStore::ctor(KeyStoreSpi* arg0, Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore::ctor(KeyStoreSpi* arg0, Provider* arg1, ::java::lang::String* arg2)");
}

java::util::Enumeration* java::security::KeyStore::aliases()
{ /* stub */
    unimplemented_(u"java::util::Enumeration* java::security::KeyStore::aliases()");
    return 0;
}

bool java::security::KeyStore::containsAlias(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::KeyStore::containsAlias(::java::lang::String* arg0)");
    return 0;
}

void java::security::KeyStore::deleteEntry(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::deleteEntry(::java::lang::String* arg0)");
}

bool java::security::KeyStore::entryInstanceOf(::java::lang::String* arg0, ::java::lang::Class* arg1)
{ /* stub */
    unimplemented_(u"bool java::security::KeyStore::entryInstanceOf(::java::lang::String* arg0, ::java::lang::Class* arg1)");
    return 0;
}

java::security::cert::Certificate* java::security::KeyStore::getCertificate(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::Certificate* java::security::KeyStore::getCertificate(::java::lang::String* arg0)");
    return 0;
}

java::lang::String* java::security::KeyStore::getCertificateAlias(::java::security::cert::Certificate* arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::KeyStore::getCertificateAlias(::java::security::cert::Certificate* arg0)");
    return 0;
}

java::security::cert::CertificateArray* java::security::KeyStore::getCertificateChain(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::security::cert::CertificateArray* java::security::KeyStore::getCertificateChain(::java::lang::String* arg0)");
    return 0;
}

java::util::Date* java::security::KeyStore::getCreationDate(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::util::Date* java::security::KeyStore::getCreationDate(::java::lang::String* arg0)");
    return 0;
}

java::lang::String* java::security::KeyStore::getDefaultType()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::security::KeyStore::getDefaultType()");
    return 0;
}

java::security::KeyStore_Entry* java::security::KeyStore::getEntry(::java::lang::String* arg0, KeyStore_ProtectionParameter* arg1)
{ /* stub */
    unimplemented_(u"java::security::KeyStore_Entry* java::security::KeyStore::getEntry(::java::lang::String* arg0, KeyStore_ProtectionParameter* arg1)");
    return 0;
}

java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0)");
    return 0;
}

java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyStore* java::security::KeyStore::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

java::security::Key* java::security::KeyStore::getKey(::java::lang::String* arg0, ::char16_tArray* arg1)
{ /* stub */
    unimplemented_(u"java::security::Key* java::security::KeyStore::getKey(::java::lang::String* arg0, ::char16_tArray* arg1)");
    return 0;
}

java::security::Provider* java::security::KeyStore::getProvider()
{ /* stub */
return provider ; /* getter */
}

java::lang::String* java::security::KeyStore::getType()
{ /* stub */
return type ; /* getter */
}

bool java::security::KeyStore::isCertificateEntry(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::KeyStore::isCertificateEntry(::java::lang::String* arg0)");
    return 0;
}

bool java::security::KeyStore::isKeyEntry(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::KeyStore::isKeyEntry(::java::lang::String* arg0)");
    return 0;
}

void java::security::KeyStore::load(KeyStore_LoadStoreParameter* arg0)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::load(KeyStore_LoadStoreParameter* arg0)");
}

void java::security::KeyStore::load(::java::io::InputStream* arg0, ::char16_tArray* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::load(::java::io::InputStream* arg0, ::char16_tArray* arg1)");
}

void java::security::KeyStore::setCertificateEntry(::java::lang::String* arg0, ::java::security::cert::Certificate* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::setCertificateEntry(::java::lang::String* arg0, ::java::security::cert::Certificate* arg1)");
}

void java::security::KeyStore::setEntry(::java::lang::String* arg0, KeyStore_Entry* arg1, KeyStore_ProtectionParameter* arg2)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::setEntry(::java::lang::String* arg0, KeyStore_Entry* arg1, KeyStore_ProtectionParameter* arg2)");
}

void java::security::KeyStore::setKeyEntry(::java::lang::String* arg0, ::int8_tArray* arg1, ::java::security::cert::CertificateArray* arg2)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::setKeyEntry(::java::lang::String* arg0, ::int8_tArray* arg1, ::java::security::cert::CertificateArray* arg2)");
}

void java::security::KeyStore::setKeyEntry(::java::lang::String* arg0, Key* arg1, ::char16_tArray* arg2, ::java::security::cert::CertificateArray* arg3)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::setKeyEntry(::java::lang::String* arg0, Key* arg1, ::char16_tArray* arg2, ::java::security::cert::CertificateArray* arg3)");
}

int32_t java::security::KeyStore::size()
{ /* stub */
    unimplemented_(u"int32_t java::security::KeyStore::size()");
    return 0;
}

void java::security::KeyStore::store(KeyStore_LoadStoreParameter* arg0)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::store(KeyStore_LoadStoreParameter* arg0)");
}

void java::security::KeyStore::store(::java::io::OutputStream* arg0, ::char16_tArray* arg1)
{ /* stub */
    unimplemented_(u"void java::security::KeyStore::store(::java::io::OutputStream* arg0, ::char16_tArray* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore", 22);
    return c;
}

java::lang::Class* java::security::KeyStore::getClass0()
{
    return class_();
}

