// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/interfaces/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::security::interfaces::RSAKey
    : public virtual ::java::lang::Object
{

    virtual ::java::math::BigInteger* getModulus() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
