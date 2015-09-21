// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingRequest.java
#include <rice/environment/processing/simple/ProcessingRequest.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/simple/ProcessingRequest_run_1.hpp>
#include <rice/environment/processing/simple/ProcessingRequest_run_2.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::ProcessingRequest::ProcessingRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::ProcessingRequest::ProcessingRequest(::rice::Executable* r, ::rice::Continuation* c, int32_t priority, int64_t seq, ::rice::environment::logging::LogManager* logging, ::rice::environment::time::TimeSource* timeSource, ::rice::selector::SelectorManager* selectorManager) 
    : ProcessingRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(r,c,priority,seq,logging,timeSource,selectorManager);
}

void rice::environment::processing::simple::ProcessingRequest::init()
{
    cancelled = false;
    running = false;
    priority = int32_t(0);
}

void rice::environment::processing::simple::ProcessingRequest::ctor(::rice::Executable* r, ::rice::Continuation* c, int32_t priority, int64_t seq, ::rice::environment::logging::LogManager* logging, ::rice::environment::time::TimeSource* timeSource, ::rice::selector::SelectorManager* selectorManager)
{
    super::ctor();
    init();
    this->r = r;
    this->c = c;
    logger = npc(logging)->getLogger(getClass(), nullptr);
    this->timeSource = timeSource;
    this->selectorManager = selectorManager;
    this->priority = priority;
    this->seq = seq;
}

void rice::environment::processing::simple::ProcessingRequest::returnResult(::java::lang::Object* o)
{
    npc(c)->receiveResult(o);
}

void rice::environment::processing::simple::ProcessingRequest::returnError(::java::lang::Exception* e)
{
    npc(c)->receiveException(e);
}

int32_t rice::environment::processing::simple::ProcessingRequest::getPriority()
{
    return priority;
}

int32_t rice::environment::processing::simple::ProcessingRequest::compareTo(ProcessingRequest* request)
{
    if(priority == npc(request)->getPriority()) {
        if(seq > npc(request)->seq)
            return 1;

        return -int32_t(1);
    }
    if(priority > npc(request)->getPriority())
        return 1;

    return -int32_t(1);
}

int32_t rice::environment::processing::simple::ProcessingRequest::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< ProcessingRequest* >(arg0));
}

void rice::environment::processing::simple::ProcessingRequest::run()
{
    if(cancelled)
        return;

    running = true;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Starting execution of "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

    try {
        auto start = npc(timeSource)->currentTimeMillis();
        auto const result = java_cast< ::java::lang::Object* >(npc(r)->execute());
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"QT: "_j)->append((npc(timeSource)->currentTimeMillis() - start))
                ->append(u" "_j)
                ->append(npc(r)->toString())->toString());

        npc(selectorManager)->invoke(new ProcessingRequest_run_1(this, result));
    } catch (::java::lang::Exception* e) {
        npc(selectorManager)->invoke(new ProcessingRequest_run_2(this, e));
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Done execution of "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

}

bool rice::environment::processing::simple::ProcessingRequest::cancel()
{
    cancelled = true;
    return !running;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::ProcessingRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.ProcessingRequest", 52);
    return c;
}

java::lang::Class* rice::environment::processing::simple::ProcessingRequest::getClass0()
{
    return class_();
}

