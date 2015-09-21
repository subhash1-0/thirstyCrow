// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/security/Signature.hpp>

struct default_init_tag;

class java::security::Signature_Delegate
    : public Signature
{

public:
    typedef Signature super;

private:
    static constexpr int32_t I_PRIV { int32_t(2) };
    static constexpr int32_t I_PRIV_SR { int32_t(3) };
    static constexpr int32_t I_PUB { int32_t(1) };
    Provider_Service* firstService {  };
    ::java::lang::Object* lock {  };
    ::java::util::Iterator* serviceIterator {  };
    SignatureSpi* sigSpi {  };
    static int32_t warnCount_;

protected:
    void ctor(SignatureSpi* arg0, ::java::lang::String* arg1);
    void ctor(Provider_Service* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2);

public: /* package */
    void chooseFirstProvider() override;
    /*void chooseProvider(int32_t arg0, Key* arg1, SecureRandom* arg2); (private) */

public:
    ::java::lang::Object* clone() override;

public: /* protected */
    ::java::lang::Object* engineGetParameter(::java::lang::String* arg0) override;
    AlgorithmParameters* engineGetParameters() override;
    void engineInitSign(PrivateKey* arg0) override;
    void engineInitSign(PrivateKey* arg0, SecureRandom* arg1) override;
    void engineInitVerify(PublicKey* arg0) override;
    void engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0) override;
    void engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1) override;
    ::int8_tArray* engineSign() override;
    int32_t engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    void engineUpdate(int8_t arg0) override;
    void engineUpdate(::java::nio::ByteBuffer* arg0) override;
    void engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    bool engineVerify(::int8_tArray* arg0) override;
    bool engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*void init_(SignatureSpi* arg0, int32_t arg1, Key* arg2, SecureRandom* arg3); (private) */
    /*static SignatureSpi* newInstance(Provider_Service* arg0); (private) */

    // Generated

public: /* package */
    Signature_Delegate(SignatureSpi* arg0, ::java::lang::String* arg1);
    Signature_Delegate(Provider_Service* arg0, ::java::util::Iterator* arg1, ::java::lang::String* arg2);
protected:
    Signature_Delegate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int32_t& warnCount();
    virtual ::java::lang::Class* getClass0();
};
