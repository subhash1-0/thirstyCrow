// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayer.java
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayer.hpp>

#include <java/lang/String.hpp>

java::lang::String*& org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_ENCRYPTION()
{
    clinit();
    return OPTION_ENCRYPTION_;
}
java::lang::String* org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_ENCRYPTION_;

java::lang::String*& org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_AUTHENTICATION()
{
    clinit();
    return OPTION_AUTHENTICATION_;
}
java::lang::String* org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_AUTHENTICATION_;

java::lang::String*& org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_CERT_SUBJECT()
{
    clinit();
    return OPTION_CERT_SUBJECT_;
}
java::lang::String* org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_CERT_SUBJECT_;

constexpr int32_t org::mpisws::p2p::transport::ssl::SSLTransportLayer::CLIENT_AUTH_NONE;

constexpr int32_t org::mpisws::p2p::transport::ssl::SSLTransportLayer::CLIENT_AUTH_REQUIRED;

constexpr int32_t org::mpisws::p2p::transport::ssl::SSLTransportLayer::CLIENT_AUTH_OPTIONAL;

constexpr int32_t org::mpisws::p2p::transport::ssl::SSLTransportLayer::NO;

constexpr int32_t org::mpisws::p2p::transport::ssl::SSLTransportLayer::YES;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ssl::SSLTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.ssl.SSLTransportLayer", 46);
    return c;
}

