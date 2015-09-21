// Generated from /pastry-2.1/src/rice/tutorial/lesson0a/TestContinuationAnon.java
#include <rice/tutorial/lesson0a/TestContinuationAnon_main_1.hpp>

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

rice::tutorial::lesson0a::TestContinuationAnon_main_1::TestContinuationAnon_main_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void rice::tutorial::lesson0a::TestContinuationAnon_main_1::receiveResult(::rice::p2p::past::PastContent* pc)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Received a "_j)->append(static_cast< ::java::lang::Object* >(pc))->toString());
}

void rice::tutorial::lesson0a::TestContinuationAnon_main_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::past::PastContent* >(result));
}

void rice::tutorial::lesson0a::TestContinuationAnon_main_1::receiveException(::java::lang::Exception* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"There was an error: "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lesson0a::TestContinuationAnon_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lesson0a::TestContinuationAnon_main_1::getClass0()
{
    return class_();
}

