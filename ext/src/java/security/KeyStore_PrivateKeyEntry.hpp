// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/KeyStore_Entry.hpp>

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

class java::security::KeyStore_PrivateKeyEntry final
    : public virtual ::java::lang::Object
    , public KeyStore_Entry
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::Set* attributes {  };
    ::java::security::cert::CertificateArray* chain {  };
    PrivateKey* privKey {  };

protected:
    void ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1);
    void ctor(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1, ::java::util::Set* arg2);

public:
    ::java::util::Set* getAttributes() override;
    ::java::security::cert::Certificate* getCertificate();
    ::java::security::cert::CertificateArray* getCertificateChain();
    PrivateKey* getPrivateKey();
    ::java::lang::String* toString() override;

    // Generated
    KeyStore_PrivateKeyEntry(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1);
    KeyStore_PrivateKeyEntry(PrivateKey* arg0, ::java::security::cert::CertificateArray* arg1, ::java::util::Set* arg2);
protected:
    KeyStore_PrivateKeyEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
