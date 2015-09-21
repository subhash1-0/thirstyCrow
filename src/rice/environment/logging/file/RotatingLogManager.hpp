// Generated from /pastry-2.1/src/rice/environment/logging/file/RotatingLogManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/file/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/AbstractLogManager.hpp>

struct default_init_tag;

class rice::environment::logging::file::RotatingLogManager
    : public ::rice::environment::logging::AbstractLogManager
{

public:
    typedef ::rice::environment::logging::AbstractLogManager super;

public: /* protected */
    ::rice::selector::TimerTask* rotateTask {  };
    ::rice::selector::TimerTask* sizeRotateTask {  };
protected:
    void ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    void ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat);

public:
    virtual void startRotateTask(::rice::selector::SelectorManager* sm);
    virtual void cancelRotateTask();

public: /* package */
    virtual void rotate();

public:
    ::java::io::PrintStream* getPrintStream() override;

public: /* protected */
    ::rice::environment::logging::Logger* constructLogger(::java::lang::String* clazz, int32_t level, bool useDefault) override;

    // Generated

public:
    RotatingLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params);
    RotatingLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat);
protected:
    RotatingLogManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RotatingLogManager_LogRotationTask;
    friend class RotatingLogManager_LogSizeRotationTask;
};
