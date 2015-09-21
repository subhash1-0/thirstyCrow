// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/swing/text/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/logging/LogManager.hpp>

struct default_init_tag;

class rice::environment::logging::AbstractLogManager
    : public virtual ::java::lang::Object
    , public virtual LogManager
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Hashtable* loggers {  };
    ::rice::environment::params::Parameters* params {  };
    ::rice::environment::time::TimeSource* time {  };
    ::java::io::PrintStream* ps {  };
    ::java::lang::String* prefix {  };
    ::java::lang::String* dateFormat {  };

public: /* package */
    int32_t globalLogLevel {  };

public: /* protected */
    bool packageOnly {  };
    bool enabled {  };

private:
    static ::java::io::PrintStream* nullPrintStream_;

public:
    ::javax::swing::text::DateFormatter* dateFormatter {  };

private:
    static ::java::lang::String* SYSTEM_OUT_;
    static ::java::lang::String* SYSTEM_ERR_;
protected:
    void ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* df);

public: /* protected */
    virtual int32_t parseVal(::java::lang::String* key);

public:
    Logger* getLogger(::java::lang::Class* clazz, ::java::lang::String* instance) override;

public: /* protected */
    virtual Logger* constructLogger(::java::lang::String* clazz, int32_t level, bool useDefault) = 0;

public:
    virtual ::rice::environment::time::TimeSource* getTimeSource();
    virtual ::java::io::PrintStream* getPrintStream();
    virtual ::java::lang::String* getPrefix();

    // Generated

public: /* protected */
    AbstractLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* df);
protected:
    AbstractLogManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public: /* protected */
    static ::java::io::PrintStream*& nullPrintStream();

public:
    static ::java::lang::String*& SYSTEM_OUT();
    static ::java::lang::String*& SYSTEM_ERR();

private:
    virtual ::java::lang::Class* getClass0();
    friend class AbstractLogManager_AbstractLogManager_1;
    friend class AbstractLogManager_NullOutputStream;
};
