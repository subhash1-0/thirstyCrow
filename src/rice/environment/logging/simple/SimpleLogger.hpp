// Generated from /pastry-2.1/src/rice/environment/logging/simple/SimpleLogger.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/HeirarchyLogger.hpp>

struct default_init_tag;

class rice::environment::logging::simple::SimpleLogger
    : public ::rice::environment::logging::HeirarchyLogger
{

public:
    typedef ::rice::environment::logging::HeirarchyLogger super;

public: /* package */
    ::java::lang::String* loggerName {  };
    ::rice::environment::logging::AbstractLogManager* alm {  };
protected:
    void ctor(::java::lang::String* loggerName, ::rice::environment::logging::AbstractLogManager* alm, int32_t level, bool useDefault);

public:
    void log(::java::lang::String* message) override;
    void logException(::java::lang::String* message, ::java::lang::Throwable* exception) override;
    ::java::lang::String* toString() override;

    // Generated
    SimpleLogger(::java::lang::String* loggerName, ::rice::environment::logging::AbstractLogManager* alm, int32_t level, bool useDefault);
protected:
    SimpleLogger(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void log(int32_t priority, ::java::lang::String* message);
    virtual void logException(int32_t priority, ::java::lang::String* message, ::java::lang::Throwable* exception);

private:
    virtual ::java::lang::Class* getClass0();
};
