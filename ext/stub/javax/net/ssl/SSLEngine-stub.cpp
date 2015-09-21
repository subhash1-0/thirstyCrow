// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/SSLEngine.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

extern void unimplemented_(const char16_t* name);
javax::net::ssl::SSLEngine::SSLEngine(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::SSLEngine::SSLEngine()
    : SSLEngine(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

javax::net::ssl::SSLEngine::SSLEngine(::java::lang::String* arg0, int32_t arg1)
    : SSLEngine(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::javax::net::ssl::SSLEngine::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::SSLEngine::ctor()");
}

void ::javax::net::ssl::SSLEngine::ctor(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::SSLEngine::ctor(::java::lang::String* arg0, int32_t arg1)");
}

javax::net::ssl::SSLSession* javax::net::ssl::SSLEngine::getHandshakeSession()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLSession* javax::net::ssl::SSLEngine::getHandshakeSession()");
    return 0;
}

java::lang::String* javax::net::ssl::SSLEngine::getPeerHost()
{ /* stub */
return peerHost ; /* getter */
}

int32_t javax::net::ssl::SSLEngine::getPeerPort()
{ /* stub */
return peerPort ; /* getter */
}

javax::net::ssl::SSLParameters* javax::net::ssl::SSLEngine::getSSLParameters()
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLParameters* javax::net::ssl::SSLEngine::getSSLParameters()");
    return 0;
}

void javax::net::ssl::SSLEngine::setSSLParameters(SSLParameters* arg0)
{ /* stub */
    unimplemented_(u"void javax::net::ssl::SSLEngine::setSSLParameters(SSLParameters* arg0)");
}

javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)");
    return 0;
}

javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBufferArray* arg1)
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBufferArray* arg1)");
    return 0;
}

javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::wrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::wrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1)");
    return 0;
}

javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::wrap(::java::nio::ByteBufferArray* arg0, ::java::nio::ByteBuffer* arg1)
{ /* stub */
    unimplemented_(u"javax::net::ssl::SSLEngineResult* javax::net::ssl::SSLEngine::wrap(::java::nio::ByteBufferArray* arg0, ::java::nio::ByteBuffer* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::SSLEngine::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.SSLEngine", 23);
    return c;
}

java::lang::Class* javax::net::ssl::SSLEngine::getClass0()
{
    return class_();
}

