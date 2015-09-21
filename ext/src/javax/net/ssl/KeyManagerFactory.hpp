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
        } // ssl
    } // net
} // javax

struct default_init_tag;

class javax::net::ssl::KeyManagerFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* algorithm {  };
    KeyManagerFactorySpi* factorySpi {  };
    ::java::security::Provider* provider {  };

protected:
    void ctor(KeyManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);

public:
    ::java::lang::String* getAlgorithm();
    static ::java::lang::String* getDefaultAlgorithm();
    static KeyManagerFactory* getInstance(::java::lang::String* arg0);
    static KeyManagerFactory* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static KeyManagerFactory* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    KeyManagerArray* getKeyManagers();
    ::java::security::Provider* getProvider();
    void init_(ManagerFactoryParameters* arg0);
    void init_(::java::security::KeyStore* arg0, ::char16_tArray* arg1);

    // Generated

public: /* protected */
    KeyManagerFactory(KeyManagerFactorySpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    KeyManagerFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
