// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java
#include <rice/pastry/leafset/testing/MergeTest_main_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::leafset::testing::MergeTest_main_2::MergeTest_main_2()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void rice::pastry::leafset::testing::MergeTest_main_2::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nodeSetUpdate("_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u","_j)
        ->append(added)
        ->append(u")"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::testing::MergeTest_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::leafset::testing::MergeTest_main_2::getClass0()
{
    return class_();
}

