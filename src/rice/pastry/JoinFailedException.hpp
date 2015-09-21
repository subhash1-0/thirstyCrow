// Generated from /pastry-2.1/src/rice/pastry/JoinFailedException.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class rice::pastry::JoinFailedException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

private:
    static constexpr int64_t serialVersionUID { int64_t(7582828712730559215LL) };
protected:
    void ctor();
    void ctor(::java::lang::String* message, ::java::lang::Throwable* cause);
    void ctor(::java::lang::String* message);
    void ctor(::java::lang::Throwable* cause);

    // Generated

public:
    JoinFailedException();
    JoinFailedException(::java::lang::String* message, ::java::lang::Throwable* cause);
    JoinFailedException(::java::lang::String* message);
    JoinFailedException(::java::lang::Throwable* cause);
protected:
    JoinFailedException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
