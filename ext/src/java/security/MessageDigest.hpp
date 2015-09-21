// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/security/MessageDigestSpi.hpp>

struct default_init_tag;

class java::security::MessageDigest
    : public MessageDigestSpi
{

public:
    typedef MessageDigestSpi super;

private:
    static constexpr int32_t INITIAL { int32_t(0) };
    static constexpr int32_t IN_PROGRESS { int32_t(1) };
    ::java::lang::String* algorithm {  };
    static ::sun::security::util::Debug* pdebug_;
    Provider* provider {  };
    static bool skipDebug_;
    int32_t state {  };

protected:
    void ctor(::java::lang::String* arg0);

public:
    ::java::lang::Object* clone() override;
    virtual ::int8_tArray* digest();
    virtual ::int8_tArray* digest(::int8_tArray* arg0);
    virtual int32_t digest(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    ::java::lang::String* getAlgorithm();
    int32_t getDigestLength();
    static MessageDigest* getInstance(::java::lang::String* arg0);
    static MessageDigest* getInstance(::java::lang::String* arg0, ::java::lang::String* arg1);
    static MessageDigest* getInstance(::java::lang::String* arg0, Provider* arg1);
    Provider* getProvider();
    static bool isEqual(::int8_tArray* arg0, ::int8_tArray* arg1);
    virtual void reset();
    ::java::lang::String* toString() override;
    virtual void update(int8_t arg0);
    virtual void update(::int8_tArray* arg0);
    void update(::java::nio::ByteBuffer* arg0);
    virtual void update(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

    // Generated

public: /* protected */
    MessageDigest(::java::lang::String* arg0);
protected:
    MessageDigest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::security::util::Debug*& pdebug();
    static bool& skipDebug();
    virtual ::java::lang::Class* getClass0();
};
