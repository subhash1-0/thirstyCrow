// Generated from /pastry-2.1/src/rice/environment/logging/file/FileLogManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/file/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/simple/SimpleLogManager.hpp>

struct default_init_tag;

class rice::environment::logging::file::FileLogManager
    : public ::rice::environment::logging::simple::SimpleLogManager
{

public:
    typedef ::rice::environment::logging::simple::SimpleLogManager super;

public: /* package */
    ::java::lang::String* filePrefix {  };
    ::java::lang::String* fileSuffix {  };
protected:
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix);
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* filePrefix, ::java::lang::String* fileSuffix, ::java::lang::String* dateFormat);
    void ctor(::rice::environment::params::Parameters* params);
    void ctor(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params);
    void ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);

private:
    static ::java::io::PrintStream* getDefaultPrintStream(::rice::environment::params::Parameters* params);
    static ::java::io::PrintStream* getPrintStream(::java::lang::String* filePrefix, ::java::lang::String* detail, ::java::lang::String* fileSuffix, bool append);

public:
    ::rice::environment::logging::LogManager* clone(::java::lang::String* detail) override;

    // Generated
    FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix);
    FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* filePrefix, ::java::lang::String* fileSuffix, ::java::lang::String* dateFormat);
    FileLogManager(::rice::environment::params::Parameters* params);
    FileLogManager(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params);
    FileLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
protected:
    FileLogManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::rice::environment::logging::LogManager* clone(::java::lang::String* detail, ::rice::environment::time::TimeSource* ts);
    ::java::io::PrintStream* getPrintStream();

public: /* protected */
    virtual ::java::lang::Object* clone();

private:
    virtual ::java::lang::Class* getClass0();
};
