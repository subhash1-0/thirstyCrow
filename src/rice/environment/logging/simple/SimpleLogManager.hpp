// Generated from /pastry-2.1/src/rice/environment/logging/simple/SimpleLogManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/AbstractLogManager.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>

struct default_init_tag;

class rice::environment::logging::simple::SimpleLogManager
    : public ::rice::environment::logging::AbstractLogManager
    , public virtual ::rice::environment::logging::CloneableLogManager
{

public:
    typedef ::rice::environment::logging::AbstractLogManager super;
protected:
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat);

public:
    ::java::io::PrintStream* getPrintStream() override;
    virtual ::rice::environment::params::Parameters* getParameters();
    ::rice::environment::time::TimeSource* getTimeSource() override;
protected:
    void ctor(::rice::environment::params::Parameters* params);
    void ctor(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params);
    void ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);

public: /* protected */
    ::rice::environment::logging::Logger* constructLogger(::java::lang::String* clazz, int32_t level, bool useDefault) override;

public:
    ::rice::environment::logging::LogManager* clone(::java::lang::String* detail) override;
    ::rice::environment::logging::LogManager* clone(::java::lang::String* detail, ::rice::environment::time::TimeSource* ts) override;
    ::java::lang::String* toString() override;

    // Generated
    SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat);
    SimpleLogManager(::rice::environment::params::Parameters* params);
    SimpleLogManager(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params);
    SimpleLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
protected:
    SimpleLogManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::String* getPrefix();
    virtual ::rice::environment::logging::Logger* getLogger(::java::lang::Class* clazz, ::java::lang::String* instance);

public: /* protected */
    virtual ::java::lang::Object* clone();

private:
    virtual ::java::lang::Class* getClass0();
};
