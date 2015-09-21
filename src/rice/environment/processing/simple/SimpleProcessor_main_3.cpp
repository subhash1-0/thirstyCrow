// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java
#include <rice/environment/processing/simple/SimpleProcessor_main_3.hpp>

#include <java/io/PrintStream.hpp>
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

rice::environment::processing::simple::SimpleProcessor_main_3::SimpleProcessor_main_3(int32_t mySeq)
    : super(*static_cast< ::default_init_tag* >(0))
    , mySeq(mySeq)
{
    clinit();
    ctor();
}

java::lang::Object* rice::environment::processing::simple::SimpleProcessor_main_3::execute()
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Executed Seq: "_j)->append(mySeq)->toString());
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::processing::simple::SimpleProcessor_main_3::getClass0()
{
    return class_();
}

