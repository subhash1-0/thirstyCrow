// Generated from /pastry-2.1/src/rice/environment/processing/Processor.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

struct rice::environment::processing::Processor
    : public virtual ::rice::Destructable
{
    virtual /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) = 0;
    virtual /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, int32_t priority, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* processBlockingIO(WorkRequest* request) = 0;
    /*void destroy(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
