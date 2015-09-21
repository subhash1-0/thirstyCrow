// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/interfaces/fwd-pastry-2.1.hpp>
#include <java/security/PublicKey.hpp>
#include <java/security/interfaces/RSAKey.hpp>

struct java::security::interfaces::RSAPublicKey
    : public virtual ::java::security::PublicKey
    , public virtual RSAKey
{
    static constexpr int64_t serialVersionUID { int64_t(-8727434096241101194LL) };

    virtual ::java::math::BigInteger* getPublicExponent() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
