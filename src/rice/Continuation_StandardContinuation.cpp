// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_StandardContinuation.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_StandardContinuation::Continuation_StandardContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_StandardContinuation::Continuation_StandardContinuation(Continuation* continuation) 
    : Continuation_StandardContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor(continuation);
}

void rice::Continuation_StandardContinuation::ctor(Continuation* continuation)
{
    super::ctor();
    parent = continuation;
}

void rice::Continuation_StandardContinuation::receiveException(::java::lang::Exception* result)
{
    npc(parent)->receiveException(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_StandardContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.StandardContinuation", 38);
    return c;
}

java::lang::Class* rice::Continuation_StandardContinuation::getClass0()
{
    return class_();
}

