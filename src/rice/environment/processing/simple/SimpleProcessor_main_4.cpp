// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java
#include <rice/environment/processing/simple/SimpleProcessor_main_4.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::SimpleProcessor_main_4::SimpleProcessor_main_4(int32_t mySeq)
    : super(*static_cast< ::default_init_tag* >(0))
    , mySeq(mySeq)
{
    clinit();
    ctor();
}

void rice::environment::processing::simple::SimpleProcessor_main_4::receiveResult(::java::lang::Object* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Received Seq: "_j)->append(mySeq)->toString());
}

void rice::environment::processing::simple::SimpleProcessor_main_4::receiveException(::java::lang::Exception* exception)
{
    npc(exception)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_4::getClass0()
{
    return class_();
}

