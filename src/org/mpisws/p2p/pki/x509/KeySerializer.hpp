// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/KeySerializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::pki::x509::KeySerializer
    : public virtual ::java::lang::Object
{
    static constexpr int8_t KEY_PRIVATE { int8_t(0) };
    static constexpr int8_t KEY_PUBLIC { int8_t(1) };
    static constexpr int8_t KEY_SECRET { int8_t(2) };
    virtual void serialize(::java::security::Key* k, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual ::java::security::Key* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException, InvalidKeySpecException, NoSuchAlgorithmException, NoSuchProviderException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
