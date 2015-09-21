// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/SSLContext.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace javax
{
    namespace net
    {
        namespace ssl
        {
typedef ::SubArray< ::javax::net::ssl::KeyManager, ::java::lang::ObjectArray > KeyManagerArray;
typedef ::SubArray< ::javax::net::ssl::TrustManager, ::java::lang::ObjectArray > TrustManagerArray;
        } // ssl
    } // net
} // javax

extern void unimplemented_(const char16_t* name);
javax::net::ssl::SSLContext::SSLContext(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::SSLContext::SSLContext(SSLContextSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
    : SSLContext(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

javax::net::ssl::SSLContext*& javax::net::ssl::SSLContext::defaultContext()
{
    clinit();
    return defaultContext_;
}
javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::defaultContext_;

void ::javax::net::ssl::SSLContext::ctor(SSLContextSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::SSLContext::ctor(SSLContextSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2)");
}

javax::net::ssl::SSLEngine* javax::net::ssl::SSLContext::createSSLEngine()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngine* javax::net::ssl::SSLContext::createSSLEngine()");
    return 0;
}

javax::net::ssl::SSLEngine* javax::net::ssl::SSLContext::createSSLEngine(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngine* javax::net::ssl::SSLContext::createSSLEngine(::java::lang::String* arg0, int32_t arg1)");
    return 0;
}

javax::net::ssl::SSLSessionContext* javax::net::ssl::SSLContext::getClientSessionContext()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLSessionContext* javax::net::ssl::SSLContext::getClientSessionContext()");
    return 0;
}

javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getDefault()
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getDefault()");
    return 0;
}

javax::net::ssl::SSLParameters* javax::net::ssl::SSLContext::getDefaultSSLParameters()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLParameters* javax::net::ssl::SSLContext::getDefaultSSLParameters()");
    return 0;
}

javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0)");
    return 0;
}

javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLContext* javax::net::ssl::SSLContext::getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1)");
    return 0;
}

java::lang::String* javax::net::ssl::SSLContext::getProtocol()
{ /* stub */
return protocol ; /* getter */
}

java::security::Provider* javax::net::ssl::SSLContext::getProvider()
{ /* stub */
return provider ; /* getter */
}

javax::net::ssl::SSLSessionContext* javax::net::ssl::SSLContext::getServerSessionContext()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLSessionContext* javax::net::ssl::SSLContext::getServerSessionContext()");
    return 0;
}

javax::net::ssl::SSLServerSocketFactory* javax::net::ssl::SSLContext::getServerSocketFactory()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLServerSocketFactory* javax::net::ssl::SSLContext::getServerSocketFactory()");
    return 0;
}

javax::net::ssl::SSLSocketFactory* javax::net::ssl::SSLContext::getSocketFactory()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLSocketFactory* javax::net::ssl::SSLContext::getSocketFactory()");
    return 0;
}

javax::net::ssl::SSLParameters* javax::net::ssl::SSLContext::getSupportedSSLParameters()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLParameters* javax::net::ssl::SSLContext::getSupportedSSLParameters()");
    return 0;
}

void javax::net::ssl::SSLContext::init_(KeyManagerArray* arg0, TrustManagerArray* arg1, ::java::security::SecureRandom* arg2)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::SSLContext::init_(KeyManagerArray* arg0, TrustManagerArray* arg1, ::java::security::SecureRandom* arg2)");
}

void javax::net::ssl::SSLContext::setDefault(SSLContext* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void javax::net::ssl::SSLContext::setDefault(SSLContext* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::SSLContext::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.SSLContext", 24);
    return c;
}

java::lang::Class* javax::net::ssl::SSLContext::getClass0()
{
    return class_();
}

