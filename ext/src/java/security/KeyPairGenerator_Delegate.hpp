// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/security/jca/fwd-pastry-2.1.hpp>
#include <java/security/KeyPairGenerator.hpp>

struct default_init_tag;

class java::security::KeyPairGenerator_Delegate final
    : public KeyPairGenerator
{

public:
    typedef KeyPairGenerator super;

private:
    static constexpr int32_t I_NONE { int32_t(1) };
    static constexpr int32_t I_PARAMS { int32_t(3) };
    static constexpr int32_t I_SIZE { int32_t(2) };
    int32_t initKeySize {  };
    ::java::security::spec::AlgorithmParameterSpec* initParams {  };
    SecureRandom* initRandom {  };
    int32_t initType {  };
    ::java::lang::Object* lock {  };
    ::java::util::Iterator* serviceIterator {  };
    std::atomic< KeyPairGeneratorSpi* > spi {  };

protected:
    void ctor(KeyPairGeneratorSpi* arg0, ::java::lang::String* arg1);
    void ctor(::sun::security::jca::GetInstance_Instance* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2);

public: /* package */
    void disableFailover() override;

public:
    KeyPair* generateKeyPair() override;
    void initialize(int32_t arg0, SecureRandom* arg1) override;
    void initialize(::java::security::spec::AlgorithmParameterSpec* arg0, SecureRandom* arg1) override;
    /*KeyPairGeneratorSpi* nextSpi(KeyPairGeneratorSpi* arg0, bool arg1); (private) */

    // Generated

public: /* package */
    KeyPairGenerator_Delegate(KeyPairGeneratorSpi* arg0, ::java::lang::String* arg1);
    KeyPairGenerator_Delegate(::sun::security::jca::GetInstance_Instance* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2);
protected:
    KeyPairGenerator_Delegate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void initialize(int32_t arg0);
    virtual void initialize(::java::security::spec::AlgorithmParameterSpec* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
