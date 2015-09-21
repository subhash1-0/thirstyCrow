// Generated from /pastry-2.1/src/rice/environment/exception/simple/SimpleExceptionStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/exception/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/exception/ExceptionStrategy.hpp>

struct default_init_tag;

class rice::environment::exception::simple::SimpleExceptionStrategy
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::exception::ExceptionStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::logging::LogManager* manager);

public:
    void handleException(::java::lang::Object* source, ::java::lang::Throwable* t) override;

    // Generated
    SimpleExceptionStrategy(::rice::environment::logging::LogManager* manager);
protected:
    SimpleExceptionStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
