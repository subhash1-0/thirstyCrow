// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::crypto::KeyGenerator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t I_NONE { int32_t(1) };
    static constexpr int32_t I_PARAMS { int32_t(3) };
    static constexpr int32_t I_RANDOM { int32_t(2) };
    static constexpr int32_t I_SIZE { int32_t(4) };
    ::java::lang::String* algorithm {  };
    int32_t initKeySize {  };
    ::java::security::spec::AlgorithmParameterSpec* initParams {  };
    ::java::security::SecureRandom* initRandom {  };
    int32_t initType {  };
    ::java::lang::Object* lock {  };
    static ::sun::security::util::Debug* pdebug_;
    ::java::security::Provider* provider {  };
    ::java::util::Iterator* serviceIterator {  };
    static bool skipDebug_;
    std::atomic< KeyGeneratorSpi* > spi {  };

    /*void ctor(::java::lang::String* arg0); (private) */
protected:
    void ctor(KeyGeneratorSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);

public: /* package */
    virtual void disableFailover();

public:
    SecretKey* generateKey();
    ::java::lang::String* getAlgorithm();
    static KeyGenerator* getInstance(::java::lang::String* arg0);
    static KeyGenerator* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static KeyGenerator* getInstance(::java::lang::String* arg0, ::java::security::Provider* arg1);
    ::java::security::Provider* getProvider();
    void init_(::java::security::SecureRandom* arg0);
    void init_(::java::security::spec::AlgorithmParameterSpec* arg0);
    void init_(int32_t arg0);
    void init_(::java::security::spec::AlgorithmParameterSpec* arg0, ::java::security::SecureRandom* arg1);
    void init_(int32_t arg0, ::java::security::SecureRandom* arg1);
    /*KeyGeneratorSpi* nextSpi(KeyGeneratorSpi* arg0, bool arg1); (private) */

    // Generated

public: /* protected */
    KeyGenerator(KeyGeneratorSpi* arg0, ::java::security::Provider* arg1, ::java::lang::String* arg2);
protected:
    KeyGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::security::util::Debug*& pdebug();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
