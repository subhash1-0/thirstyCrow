// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_ErrorContinuation.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_ErrorContinuation::Continuation_ErrorContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_ErrorContinuation::Continuation_ErrorContinuation(Continuation* continuation) 
    : Continuation_ErrorContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor(continuation);
}

void rice::Continuation_ErrorContinuation::ctor(Continuation* continuation)
{
    super::ctor();
    parent = continuation;
}

void rice::Continuation_ErrorContinuation::receiveResult(::java::lang::Object* result)
{
    npc(parent)->receiveResult(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_ErrorContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.ErrorContinuation", 35);
    return c;
}

java::lang::Class* rice::Continuation_ErrorContinuation::getClass0()
{
    return class_();
}

