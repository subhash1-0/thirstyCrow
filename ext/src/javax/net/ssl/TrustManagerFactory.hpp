// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

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
typedef ::SubArray< ::javax::net::ssl::TrustManager, ::java::lang::ObjectArray > TrustManagerArray;
        } // ssl
    } // net
} // javax

struct default_init_tag;

class javax::net::ssl::TrustManagerFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* algorithm {  };
    TrustManagerFactorySpi* factorySpi {  };
    ::java::security::Provider* provider {  };

protected:
    void ctor(TrustManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);

public:
    ::java::lang::String* getAlgorithm();
    static ::java::lang::String* getDefaultAlgorithm();
    static TrustManagerFactory* getInstance(::java::lang::String* arg0);
    static TrustManagerFactory* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static TrustManagerFactory* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    ::java::security::Provider* getProvider();
    TrustManagerArray* getTrustManagers();
    void init_(::java::security::KeyStore* arg0);
    void init_(ManagerFactoryParameters* arg0);

    // Generated

public: /* protected */
    TrustManagerFactory(TrustManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    TrustManagerFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
