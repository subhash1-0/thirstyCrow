// Generated from /pastry-2.1/src/rice/environment/random/simple/SimpleRandomSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/random/RandomSource.hpp>

struct default_init_tag;

class rice::environment::random::simple::SimpleRandomSource
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::random::RandomSource
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Random* rnd {  };
    ::rice::environment::logging::Logger* logger {  };
    ::java::lang::String* instance {  };
protected:
    void ctor(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance);
    void ctor(int64_t seed, ::rice::environment::logging::LogManager* manager);
    void ctor(::rice::environment::logging::LogManager* manager);
    void ctor(::rice::environment::logging::LogManager* manager, ::java::lang::String* instance);

public:
    virtual void setLogManager(::rice::environment::logging::LogManager* manager);

private:
    void init_(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance);

public:
    bool nextBoolean() override;
    void nextBytes(::int8_tArray* bytes) override;
    double nextDouble() override;
    float nextFloat() override;
    double nextGaussian() override;
    int32_t nextInt() override;
    int32_t nextInt(int32_t max) override;
    int64_t nextLong() override;

    // Generated
    SimpleRandomSource(int64_t seed, ::rice::environment::logging::LogManager* manager, ::java::lang::String* instance);
    SimpleRandomSource(int64_t seed, ::rice::environment::logging::LogManager* manager);
    SimpleRandomSource(::rice::environment::logging::LogManager* manager);
    SimpleRandomSource(::rice::environment::logging::LogManager* manager, ::java::lang::String* instance);
protected:
    SimpleRandomSource(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
