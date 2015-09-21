// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/KeySerializerImpl.java

#pragma once

#include <java/security/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/pki/x509/KeySerializer.hpp>

struct default_init_tag;

class org::mpisws::p2p::pki::x509::KeySerializerImpl
    : public virtual ::java::lang::Object
    , public virtual KeySerializer
{

public:
    typedef ::java::lang::Object super;
    void serialize(::java::security::Key* k, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    ::java::security::Key* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException, InvalidKeySpecException, NoSuchAlgorithmException, NoSuchProviderException) */ override;

    // Generated
    KeySerializerImpl();
protected:
    KeySerializerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
