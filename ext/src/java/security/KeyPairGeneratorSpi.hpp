// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::KeyPairGeneratorSpi
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual KeyPair* generateKeyPair() = 0;
    virtual void initialize(int32_t arg0, SecureRandom* arg1) = 0;
    virtual void initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1);

    // Generated
    KeyPairGeneratorSpi();
protected:
    KeyPairGeneratorSpi(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
