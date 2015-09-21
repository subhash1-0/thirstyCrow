// Generated from /pastry-2.1/src/rice/environment/processing/sim/SimProcessor.java
#include <rice/environment/processing/sim/SimProcessor.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/environment/processing/simple/ProcessingRequest.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::sim::SimProcessor::SimProcessor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::sim::SimProcessor::SimProcessor(::rice::selector::SelectorManager* selector) 
    : SimProcessor(*static_cast< ::default_init_tag* >(0))
{
    ctor(selector);
}

void rice::environment::processing::sim::SimProcessor::ctor(::rice::selector::SelectorManager* selector)
{
    super::ctor();
    this->selector = selector;
}

/* <R, E extends Exception> */rice::p2p::commonapi::Cancellable* rice::environment::processing::sim::SimProcessor::process(::rice::Executable* task, ::rice::Continuation* command, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log)
{
    return process(static_cast< ::rice::Executable* >(task), static_cast< ::rice::Continuation* >(command), int32_t(0), selector, ts, log);
}

/* <R, E extends Exception> */rice::p2p::commonapi::Cancellable* rice::environment::processing::sim::SimProcessor::process(::rice::Executable* task, ::rice::Continuation* command, int32_t priority, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log)
{
    auto ret = new ::rice::environment::processing::simple::ProcessingRequest(task, command, int32_t(0), int32_t(0), log, ts, selector);
    npc(selector)->invoke(ret);
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::environment::processing::sim::SimProcessor::processBlockingIO(::rice::environment::processing::WorkRequest* request)
{
    npc(selector)->invoke(request);
    return request;
}

void rice::environment::processing::sim::SimProcessor::destroy()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::sim::SimProcessor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.sim.SimProcessor", 44);
    return c;
}

java::lang::Class* rice::environment::processing::sim::SimProcessor::getClass0()
{
    return class_();
}

