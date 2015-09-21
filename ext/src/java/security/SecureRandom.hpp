// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/util/Random.hpp>

struct default_init_tag;

class java::security::SecureRandom
    : public ::java::util::Random
{

public:
    typedef ::java::util::Random super;

private:
    ::java::lang::String* algorithm {  };
    int64_t counter {  };
    MessageDigest* digest {  };
    static ::sun::security::util::Debug* pdebug_;
    Provider* provider {  };
    ::int8_tArray* randomBytes {  };
    int32_t randomBytesUsed {  };
    SecureRandomSpi* secureRandomSpi {  };
    static std::atomic< SecureRandom* > seedGenerator_;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(4940670005562187LL) };

private:
    static bool skipDebug_;
    ::int8_tArray* state {  };

protected:
    void ctor();
    void ctor(::int8_tArray* arg0);
    void ctor(SecureRandomSpi* arg0, Provider* arg1);
    /*void ctor(SecureRandomSpi* arg0, Provider* arg1, ::java::lang::String* arg2); (private) */

public:
    virtual ::int8_tArray* generateSeed(int32_t arg0);
    virtual ::java::lang::String* getAlgorithm();
    /*void getDefaultPRNG(bool arg0, ::int8_tArray* arg1); (private) */
    static SecureRandom* getInstance(::java::lang::String* arg0);
    static SecureRandom* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static SecureRandom* getInstance(::java::lang::String* arg0, Provider* arg1);
    static SecureRandom* getInstanceStrong();
    /*static ::java::lang::String* getPrngAlgorithm(); (private) */
    Provider* getProvider();

public: /* package */
    virtual SecureRandomSpi* getSecureRandomSpi();

public:
    static ::int8_tArray* getSeed(int32_t arg0);
    /*static ::int8_tArray* longToByteArray_(int64_t arg0); (private) */

public: /* protected */
    int32_t next(int32_t arg0) override;

public:
    void nextBytes(::int8_tArray* arg0) override;
    virtual void setSeed(::int8_tArray* arg0);
    void setSeed(int64_t arg0) override;

    // Generated
    SecureRandom();
    SecureRandom(::int8_tArray* arg0);

public: /* protected */
    SecureRandom(SecureRandomSpi* arg0, Provider* arg1);
protected:
    SecureRandom(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::security::util::Debug*& pdebug();
    static std::atomic< SecureRandom* >& seedGenerator();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
