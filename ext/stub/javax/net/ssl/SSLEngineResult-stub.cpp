// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/SSLEngineResult.hpp>

extern void unimplemented_(const char16_t* name);
javax::net::ssl::SSLEngineResult::SSLEngineResult(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::SSLEngineResult::SSLEngineResult(SSLEngineResult_Status* arg0, SSLEngineResult_HandshakeStatus* arg1, int32_t arg2, int32_t arg3)
    : SSLEngineResult(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}


void ::javax::net::ssl::SSLEngineResult::ctor(SSLEngineResult_Status* arg0, SSLEngineResult_HandshakeStatus* arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::net::ssl::SSLEngineResult::ctor(SSLEngineResult_Status* arg0, SSLEngineResult_HandshakeStatus* arg1, int32_t arg2, int32_t arg3)");
}

int32_t javax::net::ssl::SSLEngineResult::bytesConsumed()
{ /* stub */
    unimplemented_(u"int32_t javax::net::ssl::SSLEngineResult::bytesConsumed()");
    return 0;
}

int32_t javax::net::ssl::SSLEngineResult::bytesProduced()
{ /* stub */
    unimplemented_(u"int32_t javax::net::ssl::SSLEngineResult::bytesProduced()");
    return 0;
}

javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult::getHandshakeStatus()
{ /* stub */
return handshakeStatus ; /* getter */
}

javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult::getStatus()
{ /* stub */
return status ; /* getter */
}

java::lang::String* javax::net::ssl::SSLEngineResult::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* javax::net::ssl::SSLEngineResult::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::SSLEngineResult::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.SSLEngineResult", 29);
    return c;
}

java::lang::Class* javax::net::ssl::SSLEngineResult::getClass0()
{
    return class_();
}

