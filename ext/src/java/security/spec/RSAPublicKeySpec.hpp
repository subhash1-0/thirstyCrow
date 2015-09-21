// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/spec/KeySpec.hpp>

struct default_init_tag;

class java::security::spec::RSAPublicKeySpec
    : public virtual ::java::lang::Object
    , public virtual KeySpec
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::math::BigInteger* modulus {  };
    ::java::math::BigInteger* publicExponent {  };

protected:
    void ctor(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1);

public:
    virtual ::java::math::BigInteger* getModulus();
    virtual ::java::math::BigInteger* getPublicExponent();

    // Generated
    RSAPublicKeySpec(::java::math::BigInteger* arg0, ::java::math::BigInteger* arg1);
protected:
    RSAPublicKeySpec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
