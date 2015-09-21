// Generated from /pastry-2.1/src/rice/environment/random/RandomSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::environment::random::RandomSource
    : public virtual ::java::lang::Object
{
    virtual bool nextBoolean() = 0;
    virtual void nextBytes(::int8_tArray* bytes) = 0;
    virtual double nextDouble() = 0;
    virtual float nextFloat() = 0;
    virtual double nextGaussian() = 0;
    virtual int32_t nextInt() = 0;
    virtual int32_t nextInt(int32_t max) = 0;
    virtual int64_t nextLong() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
