// Generated from /pastry-2.1/src/rice/tutorial/lesson0a/MyContinuation.java
#include <rice/tutorial/lesson0a/MyContinuation.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/PastContent.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::lesson0a::MyContinuation::MyContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lesson0a::MyContinuation::MyContinuation()
    : MyContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::tutorial::lesson0a::MyContinuation::receiveResult(::rice::p2p::past::PastContent* pc)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Received a "_j)->append(static_cast< ::java::lang::Object* >(pc))->toString());
}

void rice::tutorial::lesson0a::MyContinuation::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::past::PastContent* >(result));
}

void rice::tutorial::lesson0a::MyContinuation::receiveException(::java::lang::Exception* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"There was an error: "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lesson0a::MyContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lesson0a.MyContinuation", 37);
    return c;
}

java::lang::Class* rice::tutorial::lesson0a::MyContinuation::getClass0()
{
    return class_();
}

