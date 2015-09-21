// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/interfaces/fwd-pastry-2.1.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/interfaces/RSAKey.hpp>

struct java::security::interfaces::RSAPrivateKey
    : public virtual ::java::security::PrivateKey
    , public virtual RSAKey
{
    static constexpr int64_t serialVersionUID { int64_t(5187144804936595022LL) };

    virtual ::java::math::BigInteger* getPrivateExponent() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
