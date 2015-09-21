// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <java/security/SignatureSpi.hpp>

struct default_init_tag;

class java::security::Signature_CipherAdapter
    : public SignatureSpi
{

public:
    typedef SignatureSpi super;

private:
    ::javax::crypto::Cipher* cipher {  };
    ::java::io::ByteArrayOutputStream* data {  };

protected:
    void ctor(::javax::crypto::Cipher* arg0);

public: /* protected */
    ::java::lang::Object* engineGetParameter(::java::lang::String* arg0) override;
    void engineInitSign(PrivateKey* arg0) override;
    void engineInitSign(PrivateKey* arg0, SecureRandom* arg1) override;
    void engineInitVerify(PublicKey* arg0) override;
    void engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1) override;
    ::int8_tArray* engineSign() override;
    void engineUpdate(int8_t arg0) override;
    void engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    bool engineVerify(::int8_tArray* arg0) override;

    // Generated

public: /* package */
    Signature_CipherAdapter(::javax::crypto::Cipher* arg0);
protected:
    Signature_CipherAdapter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual void engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0);
    virtual int32_t engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual void engineUpdate(::java::nio::ByteBuffer* arg0);
    virtual bool engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

private:
    virtual ::java::lang::Class* getClass0();
};
