// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/TrustManagerFactory.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace net
    {
        namespace ssl
        {
typedef ::SubArray< ::javax::net::ssl::TrustManager, ::java::lang::ObjectArray > TrustManagerArray;
        } // ssl
    } // net
} // javax

extern void unimplemented_(const char16_t* name);
javax::net::ssl::TrustManagerFactory::TrustManagerFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::TrustManagerFactory::TrustManagerFactory(TrustManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : TrustManagerFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::javax::net::ssl::TrustManagerFactory::ctor(TrustManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::TrustManagerFactory::ctor(TrustManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

java::lang::String* javax::net::ssl::TrustManagerFactory::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

java::lang::String* javax::net::ssl::TrustManagerFactory::getDefaultAlgorithm()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* javax::net::ssl::TrustManagerFactory::getDefaultAlgorithm()");
    return 0;
}

javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0)");
    return 0;
}

javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::TrustManagerFactory* javax::net::ssl::TrustManagerFactory::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

java::security::Provider* javax::net::ssl::TrustManagerFactory::getProvider()
{ /* stub */
return provider ; /* getter */
}

javax::net::ssl::TrustManagerArray* javax::net::ssl::TrustManagerFactory::getTrustManagers()
{ /* stub */
    unimplemented_(u"javax::net::ssl::TrustManagerArray* javax::net::ssl::TrustManagerFactory::getTrustManagers()");
    return 0;
}

void javax::net::ssl::TrustManagerFactory::init_(::java::security::KeyStore* arg0)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::TrustManagerFactory::init_(::java::security::KeyStore* arg0)");
}

void javax::net::ssl::TrustManagerFactory::init_(ManagerFactoryParameters* arg0)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::TrustManagerFactory::init_(ManagerFactoryParameters* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::TrustManagerFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.TrustManagerFactory", 33);
    return c;
}

java::lang::Class* javax::net::ssl::TrustManagerFactory::getClass0()
{
    return class_();
}

