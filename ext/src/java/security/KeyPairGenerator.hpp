// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <sun/security/jca/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/security/KeyPairGeneratorSpi.hpp>

struct default_init_tag;

class java::security::KeyPairGenerator
    : public KeyPairGeneratorSpi
{

public:
    typedef KeyPairGeneratorSpi super;

private:
    ::java::lang::String* algorithm {  };
    static ::sun::security::util::Debug* pdebug_;

public: /* package */
    Provider* provider {  };

private:
    static bool skipDebug_;

protected:
    void ctor(::java::lang::String* arg0);

public: /* package */
    virtual void disableFailover();

public:
    KeyPair* genKeyPair();
    KeyPair* generateKeyPair() override;
    virtual ::java::lang::String* getAlgorithm();
    static KeyPairGenerator* getInstance(::java::lang::String* arg0);
    /*static KeyPairGenerator* getInstance(::sun::security::jca::GetInstance_Instance* arg0, ::java::lang::String* arg1); (private) */
    static KeyPairGenerator* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static KeyPairGenerator* getInstance(::java::lang::String* arg0, Provider* arg1);
    Provider* getProvider();
    virtual void initialize(int32_t arg0);
    virtual void initialize(::java::security::spec::AlgorithmParameterSpec* arg0);
    void initialize(int32_t arg0, SecureRandom* arg1) override;
    void initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1) override;

    // Generated

public: /* protected */
    KeyPairGenerator(::java::lang::String* arg0);
protected:
    KeyPairGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::security::util::Debug*& pdebug();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
