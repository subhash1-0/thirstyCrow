// Generated from /pastry-2.1/src/rice/environment/processing/WorkRequest.java
#include <rice/environment/processing/WorkRequest.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/processing/WorkRequest_run_1.hpp>
#include <rice/environment/processing/WorkRequest_run_2.hpp>
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

rice::environment::processing::WorkRequest::WorkRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::WorkRequest::WorkRequest(::rice::Continuation* c, ::rice::selector::SelectorManager* sm) 
    : WorkRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(c,sm);
}

rice::environment::processing::WorkRequest::WorkRequest() 
    : WorkRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::processing::WorkRequest::init()
{
    cancelled = false;
    running = false;
}

void rice::environment::processing::WorkRequest::ctor(::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
{
    super::ctor();
    init();
    this->c = c;
    this->selectorManager = sm;
}

void rice::environment::processing::WorkRequest::ctor()
{
    super::ctor();
    init();
}

void rice::environment::processing::WorkRequest::returnResult(::java::lang::Object* o)
{
    npc(c)->receiveResult(o);
}

void rice::environment::processing::WorkRequest::returnError(::java::lang::Exception* e)
{
    npc(c)->receiveException(e);
}

void rice::environment::processing::WorkRequest::run()
{
    if(cancelled)
        return;

    running = true;
    try {
        auto const result = java_cast< ::java::lang::Object* >(doWork());
        npc(selectorManager)->invoke(new WorkRequest_run_1(this, result));
    } catch (::java::lang::Exception* e) {
        npc(selectorManager)->invoke(new WorkRequest_run_2(this, e));
    }
}

bool rice::environment::processing::WorkRequest::cancel()
{
    cancelled = true;
    return !running;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::WorkRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.WorkRequest", 39);
    return c;
}

java::lang::Class* rice::environment::processing::WorkRequest::getClass0()
{
    return class_();
}

