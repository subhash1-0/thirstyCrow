// Generated from /pastry-2.1/src/rice/Continuation.java
#include <rice/Continuation_NamedContinuation.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::Continuation_NamedContinuation::Continuation_NamedContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::Continuation_NamedContinuation::Continuation_NamedContinuation(::java::lang::String* name, Continuation* command) 
    : Continuation_NamedContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,command);
}

void rice::Continuation_NamedContinuation::ctor(::java::lang::String* name, Continuation* command)
{
    super::ctor();
    this->name = name;
    this->parent = command;
}

void rice::Continuation_NamedContinuation::receiveResult(::java::lang::Object* result)
{
    npc(parent)->receiveResult(result);
}

void rice::Continuation_NamedContinuation::receiveException(::java::lang::Exception* result)
{
    npc(parent)->receiveException(result);
}

java::lang::String* rice::Continuation_NamedContinuation::toString()
{
    return name;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::Continuation_NamedContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.Continuation.NamedContinuation", 35);
    return c;
}

java::lang::Class* rice::Continuation_NamedContinuation::getClass0()
{
    return class_();
}

