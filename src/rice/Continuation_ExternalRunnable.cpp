// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_ExternalRunnable.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_ExternalRunnable::Continuation_ExternalRunnable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_ExternalRunnable::Continuation_ExternalRunnable()
    : Continuation_ExternalRunnable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::Continuation_ExternalRunnable::execute(Continuation* c) /* throws(Exception) */
{
    npc(c)->receiveResult(execute());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_ExternalRunnable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.ExternalRunnable", 34);
    return c;
}

java::lang::Class* rice::Continuation_ExternalRunnable::getClass0()
{
    return class_();
}

