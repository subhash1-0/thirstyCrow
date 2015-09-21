// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::security::KeyStore
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* KEYSTORE_TYPE_;
    bool initialized {  };
    KeyStoreSpi* keyStoreSpi {  };
    static ::sun::security::util::Debug* pdebug_;
    Provider* provider {  };
    static bool skipDebug_;
    ::java::lang::String* type {  };

protected:
    void ctor(KeyStoreSpi* arg0, Provider* arg1, ::java::lang::String* arg2);

public:
    ::java::util::Enumeration* aliases();
    bool containsAlias(::java::lang::String* arg0);
    void deleteEntry(::java::lang::String* arg0);
    bool entryInstanceOf(::java::lang::String* arg0, ::java::lang::Class* arg1);
    ::java::security::cert::Certificate* getCertificate(::java::lang::String* arg0);
    ::java::lang::String* getCertificateAlias(::java::security::cert::Certificate* arg0);
    ::java::security::cert::CertificateArray* getCertificateChain(::java::lang::String* arg0);
    ::java::util::Date* getCreationDate(::java::lang::String* arg0);
    static ::java::lang::String* getDefaultType();
    KeyStore_Entry* getEntry(::java::lang::String* arg0, KeyStore_ProtectionParameter* arg1);
    static KeyStore* getInstance(::java::lang::String* arg0);
    static KeyStore* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static KeyStore* getInstance(::java::lang::String* arg0, Provider* arg1);
    Key* getKey(::java::lang::String* arg0, ::char16_tArray* arg1);
    Provider* getProvider();
    ::java::lang::String* getType();
    bool isCertificateEntry(::java::lang::String* arg0);
    bool isKeyEntry(::java::lang::String* arg0);
    void load(KeyStore_LoadStoreParameter* arg0);
    void load(::java::io::InputStream* arg0, ::char16_tArray* arg1);
    void setCertificateEntry(::java::lang::String* arg0, ::java::security::cert::Certificate* arg1);
    void setEntry(::java::lang::String* arg0, KeyStore_Entry* arg1, KeyStore_ProtectionParameter* arg2);
    void setKeyEntry(::java::lang::String* arg0, ::int8_tArray* arg1, ::java::security::cert::CertificateArray* arg2);
    void setKeyEntry(::java::lang::String* arg0, Key* arg1, ::char16_tArray* arg2, ::java::security::cert::CertificateArray* arg3);
    int32_t size();
    void store(KeyStore_LoadStoreParameter* arg0);
    void store(::java::io::OutputStream* arg0, ::char16_tArray* arg1);

    // Generated

public: /* protected */
    KeyStore(KeyStoreSpi* arg0, Provider* arg1, ::java::lang::String* arg2);
protected:
    KeyStore(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::lang::String*& KEYSTORE_TYPE();
    static ::sun::security::util::Debug*& pdebug();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
