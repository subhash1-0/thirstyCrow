// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/X509SerializerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/pki/x509/X509Serializer.hpp>
#include <java/security/cert/X509Certificate.hpp>

struct default_init_tag;

class org::mpisws::p2p::pki::x509::X509SerializerImpl
    : public virtual ::java::lang::Object
    , public virtual X509Serializer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::security::cert::CertificateFactory* certificatefactory {  };
protected:
    void ctor() /* throws(CertificateException, NoSuchProviderException) */;

public:
    virtual void serialize(::java::security::cert::X509Certificate* cert, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    ::java::security::cert::X509Certificate* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    X509SerializerImpl();
protected:
    X509SerializerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) override;

private:
    virtual ::java::lang::Class* getClass0();
};
