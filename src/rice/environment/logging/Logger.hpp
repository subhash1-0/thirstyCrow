// Generated from /pastry-2.1/src/rice/environment/logging/Logger.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::environment::logging::Logger
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t SEVERE { int32_t(1000) };
    static constexpr int32_t WARNING { int32_t(900) };
    static constexpr int32_t INFO { int32_t(800) };
    static constexpr int32_t CONFIG { int32_t(700) };
    static constexpr int32_t FINE { int32_t(500) };
    static constexpr int32_t FINER { int32_t(400) };
    static constexpr int32_t FINEST { int32_t(300) };
    static constexpr int32_t ALL { int32_t(-0x7fffffff-1) };
    static constexpr int32_t OFF { int32_t(2147483647) };
    int32_t level {  };
    virtual void log(::java::lang::String* message) = 0;
    virtual void logException(::java::lang::String* message, ::java::lang::Throwable* exception) = 0;
    virtual void log(int32_t priority, ::java::lang::String* message);
    virtual void logException(int32_t priority, ::java::lang::String* message, ::java::lang::Throwable* exception);

    // Generated
    Logger();
protected:
    void ctor();
    Logger(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
