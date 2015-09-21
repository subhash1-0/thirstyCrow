// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java
#include <rice/environment/processing/simple/SimpleProcessor_main_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::SimpleProcessor_main_2::SimpleProcessor_main_2()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void rice::environment::processing::simple::SimpleProcessor_main_2::receiveResult(::java::lang::Object* result)
{
    npc(::java::lang::System::out())->println(u"Done blocking."_j);
}

void rice::environment::processing::simple::SimpleProcessor_main_2::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_2::getClass0()
{
    return class_();
}

