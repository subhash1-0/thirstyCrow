// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class javax::net::ssl::SSLContext
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    SSLContextSpi* contextSpi {  };
    static SSLContext* defaultContext_;
    ::java::lang::String* protocol {  };
    ::java::security::Provider* provider {  };

protected:
    void ctor(SSLContextSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);

public:
    SSLEngine* createSSLEngine();
    SSLEngine* createSSLEngine(::java::lang::String* arg0, int32_t arg1);
    SSLSessionContext* getClientSessionContext();
    static SSLContext* getDefault();
    SSLParameters* getDefaultSSLParameters();
    static SSLContext* getInstance(::java::lang::String* arg0);
    static SSLContext* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static SSLContext* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    ::java::lang::String* getProtocol();
    ::java::security::Provider* getProvider();
    SSLSessionContext* getServerSessionContext();
    SSLServerSocketFactory* getServerSocketFactory();
    SSLSocketFactory* getSocketFactory();
    SSLParameters* getSupportedSSLParameters();
    void init_(KeyManagerArray* arg0, TrustManagerArray* arg1, ::java::security::SecureRandom* arg2);
    static void setDefault(SSLContext* arg0);

    // Generated

public: /* protected */
    SSLContext(SSLContextSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    SSLContext(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static SSLContext*& defaultContext();
    virtual ::java::lang::Class* getClass0();
};
