// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/spec/AlgorithmParameterSpec.hpp>

struct default_init_tag;

class java::security::spec::RSAKeyGenParameterSpec
    : public virtual ::java::lang::Object
    , public virtual AlgorithmParameterSpec
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::math::BigInteger* F0_;
    static ::java::math::BigInteger* F4_;
    int32_t keysize {  };
    ::java::math::BigInteger* publicExponent {  };

protected:
    void ctor(int32_t arg0, ::java::math::BigInteger* arg1);

public:
    virtual int32_t getKeysize();
    virtual ::java::math::BigInteger* getPublicExponent();

    // Generated
    RSAKeyGenParameterSpec(int32_t arg0, ::java::math::BigInteger* arg1);
protected:
    RSAKeyGenParameterSpec(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::math::BigInteger*& F0();
    static ::java::math::BigInteger*& F4();

private:
    virtual ::java::lang::Class* getClass0();
};
