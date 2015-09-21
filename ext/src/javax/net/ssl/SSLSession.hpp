// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <javax/security/cert/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
} // java

namespace javax
{
    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::javax::security::cert::Certificate, ::java::lang::ObjectArray > CertificateArray;
typedef ::SubArray< ::javax::security::cert::X509Certificate, CertificateArray > X509CertificateArray;
        } // cert
    } // security
} // javax

struct javax::net::ssl::SSLSession
    : public virtual ::java::lang::Object
{

    virtual int32_t getApplicationBufferSize() = 0;
    virtual ::java::lang::String* getCipherSuite() = 0;
    virtual int64_t getCreationTime() = 0;
    virtual ::int8_tArray* getId() = 0;
    virtual int64_t getLastAccessedTime() = 0;
    virtual ::java::security::cert::CertificateArray* getLocalCertificates() = 0;
    virtual ::java::security::Principal* getLocalPrincipal() = 0;
    virtual int32_t getPacketBufferSize() = 0;
    virtual ::javax::security::cert::X509CertificateArray* getPeerCertificateChain() = 0;
    virtual ::java::security::cert::CertificateArray* getPeerCertificates() = 0;
    virtual ::java::lang::String* getPeerHost() = 0;
    virtual int32_t getPeerPort() = 0;
    virtual ::java::security::Principal* getPeerPrincipal() = 0;
    virtual ::java::lang::String* getProtocol() = 0;
    virtual SSLSessionContext* getSessionContext() = 0;
    virtual ::java::lang::Object* getValue(::java::lang::String* arg0) = 0;
    virtual ::java::lang::StringArray* getValueNames() = 0;
    virtual void invalidate() = 0;
    virtual bool isValid() = 0;
    virtual void putValue(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;
    virtual void removeValue(::java::lang::String* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
