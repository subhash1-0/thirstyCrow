// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/SimpleProcessor.hpp>

struct default_init_tag;

class rice::environment::processing::simple::UnifiedProcessor
    : public SimpleProcessor
{

public:
    typedef SimpleProcessor super;

public: /* package */
    ::rice::selector::SelectorManager* sman {  };
    ::rice::environment::time::TimeSource* ts {  };
    ::rice::environment::logging::LogManager* log {  };
    ::rice::Continuation* bogusContinuation {  };
protected:
    void ctor(::java::lang::String* name, ::rice::selector::SelectorManager* sman, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log);

public:
    ::rice::p2p::commonapi::Cancellable* processBlockingIO(::rice::environment::processing::WorkRequest* workRequest) override;

    // Generated
    UnifiedProcessor(::java::lang::String* name, ::rice::selector::SelectorManager* sman, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log);
protected:
    UnifiedProcessor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class UnifiedProcessor_UnifiedProcessor_1;
    friend class UnifiedProcessor_processBlockingIO_2;
};
