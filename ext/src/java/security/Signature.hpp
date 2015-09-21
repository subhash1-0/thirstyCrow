// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/security/spec/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/security/jca/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/security/SignatureSpi.hpp>

struct default_init_tag;

class java::security::Signature
    : public SignatureSpi
{

public:
    typedef SignatureSpi super;

private:
    static ::java::lang::String* RSA_CIPHER_;
    static ::java::lang::String* RSA_SIGNATURE_;

public: /* protected */
    static constexpr int32_t SIGN { int32_t(2) };
    static constexpr int32_t UNINITIALIZED { int32_t(0) };
    static constexpr int32_t VERIFY { int32_t(3) };

private:
    ::java::lang::String* algorithm {  };
    static ::sun::security::util::Debug* debug_;
    static ::sun::security::util::Debug* pdebug_;

public: /* package */
    Provider* provider {  };

private:
    static ::java::util::List* rsaIds_;
    static ::java::util::Map* signatureInfo_;
    static bool skipDebug_;

public: /* protected */
    int32_t state {  };

protected:
    void ctor(::java::lang::String* arg0);

public: /* package */
    virtual void chooseFirstProvider();

public:
    ::java::lang::Object* clone() override;
    ::java::lang::String* getAlgorithm();
    static Signature* getInstance(::java::lang::String* arg0);
    /*static Signature* getInstance(::sun::security::jca::GetInstance_Instance* arg0, ::java::lang::String* arg1); (private) */
    static Signature* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static Signature* getInstance(::java::lang::String* arg0, Provider* arg1);
    /*static Signature* getInstanceRSA(Provider* arg0); (private) */
    ::java::lang::Object* getParameter(::java::lang::String* arg0);
    AlgorithmParameters* getParameters();
    Provider* getProvider();
    void initSign(PrivateKey* arg0);
    void initSign(PrivateKey* arg0, SecureRandom* arg1);
    void initVerify(PublicKey* arg0);
    void initVerify(::java::security::cert::Certificate* arg0);
    /*static bool isSpi(Provider_Service* arg0); (private) */
    void setParameter(::java::security::spec::AlgorithmParameterSpec* arg0);
    void setParameter(::java::lang::String* arg0, ::java::lang::Object* arg1);
    ::int8_tArray* sign();
    int32_t sign(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    ::java::lang::String* toString() override;
    void update(int8_t arg0);
    void update(::int8_tArray* arg0);
    void update(::java::nio::ByteBuffer* arg0);
    void update(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    bool verify(::int8_tArray* arg0);
    bool verify(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated

public: /* protected */
    Signature(::java::lang::String* arg0);
protected:
    Signature(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::lang::String*& RSA_CIPHER();
    static ::java::lang::String*& RSA_SIGNATURE();
    static ::sun::security::util::Debug*& debug();
    static ::sun::security::util::Debug*& pdebug();
    static ::java::util::List*& rsaIds();
    static ::java::util::Map*& signatureInfo();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
