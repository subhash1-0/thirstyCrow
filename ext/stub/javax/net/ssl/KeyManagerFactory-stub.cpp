// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/KeyManagerFactory.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace net
    {
        namespace ssl
        {
typedef ::SubArray< ::javax::net::ssl::KeyManager, ::java::lang::ObjectArray > KeyManagerArray;
        } // ssl
    } // net
} // javax

extern void unimplemented_(const char16_t* name);
javax::net::ssl::KeyManagerFactory::KeyManagerFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::KeyManagerFactory::KeyManagerFactory(KeyManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : KeyManagerFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::javax::net::ssl::KeyManagerFactory::ctor(KeyManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::KeyManagerFactory::ctor(KeyManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

java::lang::String* javax::net::ssl::KeyManagerFactory::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

java::lang::String* javax::net::ssl::KeyManagerFactory::getDefaultAlgorithm()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* javax::net::ssl::KeyManagerFactory::getDefaultAlgorithm()");
    return 0;
}

javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0)");
    return 0;
}

javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::KeyManagerFactory* javax::net::ssl::KeyManagerFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

javax::net::ssl::KeyManagerArray* javax::net::ssl::KeyManagerFactory::getKeyManagers()
{ /* stub */
    unimplemented_(u"javax::net::ssl::KeyManagerArray* javax::net::ssl::KeyManagerFactory::getKeyManagers()");
    return 0;
}

java::security::Provider* javax::net::ssl::KeyManagerFactory::getProvider()
{ /* stub */
return provider ; /* getter */
}

void javax::net::ssl::KeyManagerFactory::init_(ManagerFactoryParameters* arg0)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::KeyManagerFactory::init_(ManagerFactoryParameters* arg0)");
}

void javax::net::ssl::KeyManagerFactory::init_(::java::security::KeyStore* arg0, ::char16_tArray* arg1)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::KeyManagerFactory::init_(::java::security::KeyStore* arg0, ::char16_tArray* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::KeyManagerFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.KeyManagerFactory", 31);
    return c;
}

java::lang::Class* javax::net::ssl::KeyManagerFactory::getClass0()
{
    return class_();
}

