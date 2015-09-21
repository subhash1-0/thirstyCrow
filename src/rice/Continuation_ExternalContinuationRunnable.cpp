// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_ExternalContinuationRunnable.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation_ExternalContinuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_ExternalContinuationRunnable::Continuation_ExternalContinuationRunnable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_ExternalContinuationRunnable::Continuation_ExternalContinuationRunnable() 
    : Continuation_ExternalContinuationRunnable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::Continuation_ExternalContinuationRunnable::ctor()
{
    super::ctor();
    e = new Continuation_ExternalContinuation();
}

void rice::Continuation_ExternalContinuationRunnable::run()
{
    try {
        execute(e);
    } catch (::java::lang::Exception* exc) {
        npc(e)->receiveException(exc);
    }
}

java::lang::Object* rice::Continuation_ExternalContinuationRunnable::invoke(::rice::selector::SelectorManager* sm) /* throws(Exception) */
{
    npc(sm)->invoke(this);
    npc(e)->sleep();
    if(npc(e)->exceptionThrown())
        throw npc(e)->getException();

    return npc(e)->getResult();
}

java::lang::Object* rice::Continuation_ExternalContinuationRunnable::invoke(::rice::environment::Environment* env) /* throws(Exception) */
{
    return invoke(npc(env)->getSelectorManager());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_ExternalContinuationRunnable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.ExternalContinuationRunnable", 46);
    return c;
}

java::lang::Class* rice::Continuation_ExternalContinuationRunnable::getClass0()
{
    return class_();
}

