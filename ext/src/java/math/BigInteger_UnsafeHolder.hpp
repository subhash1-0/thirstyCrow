// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::math::BigInteger_UnsafeHolder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static int64_t magOffset_;
    static int64_t signumOffset_;
    static ::sun::misc::Unsafe* unsafe_;

    /*void ctor(); (private) */

public: /* package */
    static void putMag(BigInteger* arg0, ::int32_tArray* arg1);
    static void putSign(BigInteger* arg0, int32_t arg1);

    // Generated

public:
    BigInteger_UnsafeHolder();
protected:
    BigInteger_UnsafeHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int64_t& magOffset();
    static int64_t& signumOffset();
    static ::sun::misc::Unsafe*& unsafe();
    virtual ::java::lang::Class* getClass0();
};
