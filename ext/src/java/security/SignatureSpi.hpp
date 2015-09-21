// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::SignatureSpi
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    SecureRandom* appRandom {  };

protected:
    void ctor();

public:
    ::java::lang::Object* clone() override;

public: /* protected */
    virtual ::java::lang::Object* engineGetParameter(::java::lang::String* arg0) = 0;
    virtual AlgorithmParameters* engineGetParameters();
    virtual void engineInitSign(PrivateKey* arg0) = 0;
    virtual void engineInitSign(PrivateKey* arg0, SecureRandom* arg1);
    virtual void engineInitVerify(PublicKey* arg0) = 0;
    virtual void engineSetParameter(::java::security::spec::AlgorithmParameterSpec* arg0);
    virtual void engineSetParameter(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;
    virtual ::int8_tArray* engineSign() = 0;
    virtual int32_t engineSign(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    virtual void engineUpdate(int8_t arg0) = 0;
    virtual void engineUpdate(::java::nio::ByteBuffer* arg0);
    virtual void engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2) = 0;
    virtual bool engineVerify(::int8_tArray* arg0) = 0;
    virtual bool engineVerify(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated

public:
    SignatureSpi();
protected:
    SignatureSpi(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
