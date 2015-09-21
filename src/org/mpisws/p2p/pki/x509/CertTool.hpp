// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/CertTool.java

#pragma once

#include <java/security/fwd-pastry-2.1.hpp>
#include <org/bouncycastle/jce/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::pki::x509::CertTool
    : public virtual ::java::lang::Object
{
    virtual ::org::bouncycastle::jce::PKCS10CertificationRequest* generateCertRequest(::java::security::KeyPair* pair) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
