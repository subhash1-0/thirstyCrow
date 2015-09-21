// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_ListenerContinuation.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_ListenerContinuation::Continuation_ListenerContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_ListenerContinuation::Continuation_ListenerContinuation(::java::lang::String* name, ::rice::environment::Environment* env) 
    : Continuation_ListenerContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,env);
}

void rice::Continuation_ListenerContinuation::ctor(::java::lang::String* name, ::rice::environment::Environment* env)
{
    super::ctor();
    this->name = name;
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
}

void rice::Continuation_ListenerContinuation::receiveResult(::java::lang::Object* result)
{
}

void rice::Continuation_ListenerContinuation::receiveException(::java::lang::Exception* result)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR - Received exception "_j)->append(static_cast< ::java::lang::Object* >(result))
            ->append(u" during task "_j)
            ->append(name)->toString(), result);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_ListenerContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.ListenerContinuation", 38);
    return c;
}

java::lang::Class* rice::Continuation_ListenerContinuation::getClass0()
{
    return class_();
}

