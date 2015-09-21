// Generated from /pastry-2.1/src/rice/environment/processing/sim/SimProcessor.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/sim/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/processing/Processor.hpp>

struct default_init_tag;

class rice::environment::processing::sim::SimProcessor
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::processing::Processor
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::selector::SelectorManager* selector {  };
protected:
    void ctor(::rice::selector::SelectorManager* selector);

public:
    /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) override;
    /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, int32_t priority, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) override;
    ::rice::p2p::commonapi::Cancellable* processBlockingIO(::rice::environment::processing::WorkRequest* request) override;
    void destroy() override;

    // Generated
    SimProcessor(::rice::selector::SelectorManager* selector);
protected:
    SimProcessor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
