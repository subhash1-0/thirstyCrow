// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/CertificateManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::identity::CertificateManager
    : public virtual ::java::lang::Object
{
    virtual ::int8_tArray* sign(::int8_tArray* bytes) = 0;
    virtual int32_t verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature) = 0;
    virtual bool hasCertificate(::java::lang::Object* id) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual int16_t getSignatureSizeBytes() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
