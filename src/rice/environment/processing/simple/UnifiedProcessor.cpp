// Generated from /pastry-2.1/src/rice/environment/processing/simple/UnifiedProcessor.java
#include <rice/environment/processing/simple/UnifiedProcessor.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/processing/simple/BlockingIOThread.hpp>
#include <rice/environment/processing/simple/UnifiedProcessor_UnifiedProcessor_1.hpp>
#include <rice/environment/processing/simple/UnifiedProcessor_processBlockingIO_2.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::UnifiedProcessor::UnifiedProcessor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::UnifiedProcessor::UnifiedProcessor(::java::lang::String* name, ::rice::selector::SelectorManager* sman, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) 
    : UnifiedProcessor(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,sman,ts,log);
}

void rice::environment::processing::simple::UnifiedProcessor::ctor(::java::lang::String* name, ::rice::selector::SelectorManager* sman, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log)
{
    super::ctor(name);
    this->sman = sman;
    this->ts = ts;
    this->log = log;
    bogusContinuation = new UnifiedProcessor_UnifiedProcessor_1(this);
    npc(bioThread)->destroy();
}

rice::p2p::commonapi::Cancellable* rice::environment::processing::simple::UnifiedProcessor::processBlockingIO(::rice::environment::processing::WorkRequest* workRequest)
{
    return process(static_cast< ::rice::Executable* >(new UnifiedProcessor_processBlockingIO_2(this, workRequest)), static_cast< ::rice::Continuation* >(bogusContinuation), sman, ts, log);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.UnifiedProcessor", 51);
    return c;
}

java::lang::Class* rice::environment::processing::simple::UnifiedProcessor::getClass0()
{
    return class_();
}

